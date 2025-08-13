#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import subprocess
from datetime import datetime

# ======= CONFIGURAZIONE =======
REPO_PATH = "/home/aabate/Documenti/PROGR/c-progr"  # <-- CAMBIA con il path locale
OUTPUT_TEX = "template.tex"
OUTPUT_PDF = "c_programming.pdf"
TITOLO = "C Programming"
AUTORE = "Alberto Abate"
DATA = datetime.today().strftime("%d %B %Y")

# Margini
MARGINI = {
    "top": "1.5cm",
    "bottom": "1.5cm",
    "left": "2cm",
    "right": "1.5cm"
}

# Ordine dei capitoli (solo cartelle effettive)
ORDINE_CAPITOLI = [
    "C_Basics",
    "Control_Flow",
    "Functions",
    "Arrays",
    "Pointers",
    "Strings",
    "Algorithms",
    "Recursion",
    "Memory_Management",
    "Structures"
]

# Cartelle da escludere
ESCLUSI = {".git", "minted-manuale"}
# ==============================

def escape_latex(text):
    """Escapa caratteri speciali per LaTeX."""
    replacements = {
        '&': r'\&', '%': r'\%', '$': r'\$', '#': r'\#',
        '_': r'\_', '{': r'\{', '}': r'\}',
        '~': r'\textasciitilde{}', '^': r'\textasciicircum{}',
        '\\': r'\textbackslash{}',
    }
    for old, new in replacements.items():
        text = text.replace(old, new)
    return text

# ======= CREAZIONE DOCUMENTO LATEX =======
latex = []

latex.append(r"\documentclass[11pt]{book}")
latex.append(r"\usepackage{fontspec}")
latex.append(r"\usepackage{xcolor}")
latex.append(r"\usepackage{geometry}")
latex.append(r"\usepackage{hyperref}")
latex.append(r"\usepackage{minted}")

# Margini
latex.append(r"\geometry{top=%s, bottom=%s, left=%s, right=%s}" %
             (MARGINI["top"], MARGINI["bottom"], MARGINI["left"], MARGINI["right"]))

# Hyperref
latex.append(r"\hypersetup{colorlinks=true, linkcolor=blue, urlcolor=blue}")

# Fancy header
latex.append(r"\usepackage{fancyhdr}")
latex.append(r"\pagestyle{fancy}")
latex.append(r"\fancyhf{}")
latex.append(r"\fancyhead[C]{\small\leftmark}")
latex.append(r"\renewcommand{\chaptermark}[1]{\markboth{#1}{}}")
latex.append(r"\renewcommand{\headrulewidth}{0.4pt}")
latex.append(r"\fancyfoot[C]{\thepage}")

# Titolo
latex.append(r"\title{%s}" % escape_latex(TITOLO))
latex.append(r"\author{%s}" % escape_latex(AUTORE))
latex.append(r"\date{%s}" % escape_latex(DATA))

latex.append(r"\begin{document}")
latex.append(r"\maketitle")
latex.append(r"\tableofcontents")
latex.append(r"\newpage")

# ======= CAPITOLI =======
for capitolo in ORDINE_CAPITOLI:
    if capitolo in ESCLUSI:
        print(f"[DEBUG] Capitolo '{capitolo}' escluso")
        continue

    capitolo_path = os.path.join(REPO_PATH, capitolo)
    print(f"[DEBUG] Verifico cartella: {capitolo_path}")

    if os.path.isdir(capitolo_path):
        print(f"[DEBUG] Cartella trovata: {capitolo_path}")
        capitolo_title = capitolo.replace("_", " ")
        latex.append(r"\chapter{%s}" % escape_latex(capitolo_title))

        c_files = sorted([f for f in os.listdir(capitolo_path) if f.endswith(".c")])
        if not c_files:
            print(f"[WARNING] Nessun file .c trovato in {capitolo_path}")
        else:
            print(f"[DEBUG] File .c trovati in {capitolo}: {c_files}")

        for c_file in c_files:
            file_path = os.path.join(capitolo_path, c_file)
            latex.append(r"\clearpage")
            latex.append(r"\begin{minted}[breaklines, fontsize=\small]{c}")
            try:
                with open(file_path, "r", encoding="utf-8") as f:
                    latex.append(f.read())
            except Exception as e:
                print(f"[ERROR] Impossibile leggere {file_path}: {e}")
            latex.append(r"\end{minted}")
    else:
        print(f"[WARNING] Cartella non trovata: {capitolo_path}")

latex.append(r"\end{document}")

# ======= SCRITTURA FILE .TEX =======
with open(OUTPUT_TEX, "w", encoding="utf-8") as f:
    f.write("\n".join(latex))

print(f"{OUTPUT_TEX} generato con successo!")

# ======= COMPILAZIONE CON XELATEX =======
print("Compilazione con XeLaTeX in corso...")
subprocess.run(["xelatex", "-shell-escape", OUTPUT_TEX])
subprocess.run(["xelatex", "-shell-escape", OUTPUT_TEX])  # due volte per TOC

if os.path.exists(OUTPUT_PDF):
    print(f"{OUTPUT_PDF} creato con successo!")

# ======= PULIZIA FILE TEMPORANEI =======
TEMP_EXTENSIONS = [".aux", ".log", ".out", ".toc", ".lof", ".lot", ".lol"]
for ext in TEMP_EXTENSIONS:
    temp_file = OUTPUT_TEX.replace(".tex", ext)
    if os.path.exists(temp_file):
        os.remove(temp_file)
        print(f"Rimosso {temp_file}")
