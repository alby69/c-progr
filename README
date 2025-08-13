# C Language Tutorial

This repository contains a collection of C programming exercises organized into a comprehensive tutorial, progressing from basic concepts to more advanced topics.

The exercises are sorted into numbered directories, each focusing on a specific area of the C language.

## How to Generate the PDF Book

This repository includes a Python script, `genera_manual.py`, that automates the creation of a complete PDF book from the tutorial files.

### 1. Prerequisites

Before you can generate the PDF, you must have the following software installed on your system:

1.  **Python 3:** The script is written in Python 3.
2.  **A LaTeX Distribution:** You need a full LaTeX environment like [TeX Live](https://www.tug.org/texlive/) (for Linux/Windows), [MiKTeX](https://miktex.org/) (for Windows), or [MacTeX](https://www.tug.org/mactex/) (for macOS). The script specifically uses the `xelatex` command, which should be included in any modern LaTeX distribution.
3.  **Pygments:** This is a Python library required by the `minted` package for code syntax highlighting. You can install it using pip:
    ```sh
    pip install Pygments
    ```
4.  **The `minted` LaTeX package:** This package is used for formatting the C code in the PDF. It can usually be installed using your LaTeX distribution's package manager. For example, with TeX Live:
    ```sh
    tlmgr install minted
    ```

### 2. Configuration

This is the most important step. You must tell the script where to find the tutorial files on your local machine.

1.  Open the `genera_manual.py` file in a text editor.
2.  Find the following line at the top of the script:
    ```python
    REPO_PATH = "/home/aabate/Documenti/PROGR/c-progr"  # <-- CAMBIA con il path locale
    ```
3.  **Change the path** inside the quotes to the **full, absolute path** of this `c-progr` repository folder on your computer.

### 3. Generation

Once the prerequisites are installed and the path is configured:

1.  Open your terminal or command prompt.
2.  Navigate into the root directory of this `c-progr` repository.
3.  Run the script with the following command:
    ```sh
    python3 genera_manual.py
    ```

The script will print status messages as it works. It will first create a `manuale.tex` file, then compile it twice using `xelatex`. If everything is successful, you will find a new file named `manuale.pdf` in this directory.
