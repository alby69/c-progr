#!/usr/bin/env python3
import os

# Configurazione
repo_path = "."  # percorso radice repo
output_file = "manuale.tex"
chapter_order = sorted(
    [d for d in os.listdir(repo_path) if os.path.isdir(d) and d[0].isdigit()]
)  # cartelle che iniziano con cifra

# Intestazione LaTeX
latex_header = r"""\documentclass[a4paper,11pt,oneside]{book}
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\usepackage[italian]{babel}
\usepackage{geometry}
\geometry{margin=2.5cm}
\usepackage{fontspec}
\setmainfont{Fira Sans}
\setmonofont{Fira Code}
\usepackage{xcolor}
\definecolor{codebg}{RGB}{248,248,248}
\usepackage{minted}
\setminted{
    frame=single,
    framesep=3mm,
    fontsize=\small,
    bgcolor=codebg,
    breaklines=false,
    linenos=true,
    numbersep=5pt
}
\usepackage{hyperref}
\hypersetup{
    colorlinks=true,
    linkcolor=blue,
    urlcolor=cyan
}
\usepackage{tocloft}
\usepackage{graphicx}
\usepackage{pdfpages}
\usepackage{float}
\usepackage{fvextra}
\DefineVerbatimEnvironment{Verbatim}{Verbatim}{breaklines=false}

\begin{document}
\begin{titlepage}
    \centering
    \vspace*{4cm}
    {\Huge\bfseries Manuale di Programmazione in C\par}
    \vspace{1cm}
    {\Large Basato sul repository \texttt{c-progr}\par}
    \vfill
    {\large Autore: Tuo Nome\par}
    {\large \today\par}
\end{titlepage}

\frontmatter
\tableofcontents
\listoflistings
\mainmatter
"""

# Footer LaTeX
latex_footer = r"""
\backmatter
\chapter*{Licenza}
Il contenuto di questo manuale è distribuito secondo la licenza del repository originale.
\end{document}
"""

# Generazione contenuto
content = [latex_header]

for chapter in chapter_order:
    chapter_name = chapter.split("_", 1)[-1].replace("_", " ")
    content.append(f"\\chapter{{{chapter_name}}}\n")
    files = sorted(
        [f for f in os.listdir(chapter) if f.endswith((".c", ".h"))]
    )
    for file in files:
        filepath = os.path.join(chapter, file)
        # Escapa backslash e underscore per LaTeX
        latex_path = filepath.replace("\\", "/").replace("_", "\\_")
        content.append(f"\\inputminted{{c}}{{{latex_path}}}\n")

content.append(latex_footer)

# Salvataggio
with open(output_file, "w", encoding="utf-8") as f:
    f.write("\n".join(content))

print(f"File LaTeX generato: {output_file}")
print("Compila con: xelatex -shell-escape manuale.tex")
