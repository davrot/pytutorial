## VS Code Configuration
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Configure VS Code for Python

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## The configuration 

You will need to adapt it to your needs...

```json
{
    // The color theme plus mini map
    "workbench.colorTheme": "One Dark Pro",
    // Adding the lines for Python 
    "editor.rulers": [
        80,
        120
    ],
    // I don't like the automatic interference 
    "editor.autoClosingBrackets": "never",
    "editor.autoClosingDelete": "never",
    "editor.autoClosingOvertype": "never",
    "editor.autoClosingQuotes": "never",
    "editor.autoSurround": "never",
    // Stopping drag and drop from interfering 
    "editor.dragAndDrop": false,
    // I don't like if I hover over a word and 
    // VS Code blocks my view with information
    "editor.hover.delay": 5000,
    // Bigger fonts (bad eyes)
    "editor.fontSize": 18,
    // Black does it's work on saving
    "editor.formatOnSave": true,
    // I decided to violate these rules:
    // E402: Module level import not at top of file https://www.flake8rules.com/rules/E402.html
    // E501: Line too long (> 79 characters) https://www.flake8rules.com/rules/E501.html
    // W503: Line break occurred before a binary operator https://www.flake8rules.com/rules/W503.html
    //       PEP8 was changed; replaced by W504 "Line break occurred after a binary operator https://www.flake8rules.com/rules/W504.html"
    // E203: Whitespace before ':' https://www.flake8rules.com/rules/E203.html Black wants this really badly!
    "flake8.args": [
        "--ignore=E402,E501,W503,E203"
    ],
    // Microsoft leave me alone! 
    "extensions.ignoreRecommendations": true
}
```
