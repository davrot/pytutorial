# Baking bread
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Disassembling the process of baking bread as a flow chart. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Baking bread

{% raw %} 

  <pre class="mermaid">
    graph TD
    A(["Start"]) --> B{"Ingredients Ready?"}
    B -->|"Yes"| C("Preheat Oven")
    B -->|"No"| D[["Gather Ingredients"]]
    D --> C
    C --> md[["Make Dough"]] --> E("Knead Dough")
    E --> F{"First Rise Complete?"}
    F -->|"Yes"| G("Punch Down Dough")
    F -->|"No"| E
    G --> H("Shape Loaf")
    H --> I{"Second Rise Complete?"}
    I -->|"Yes"| J("Bake")
    I -->|"No"| H
    J --> K(["Stop"])
  </pre>  
{% endraw %}

## Function Gather Ingredients

{% raw %} 
  <pre class="mermaid">
    graph TD
      gi[["Gather Ingredients"]] --> A(["Start"]) --> B("Go to Kitchen")
      B --> C("Open Pantry")
      C --> D1("Get Flour")
      D1 --> D2("Get Sugar")
      D2 --> D3("Get Salt")
      D3 --> E("Close Pantry")
      E --> F("Open Refrigerator")
      F --> G1("Get Water")
      G1 --> G2("Get Yeast")
      G2 --> H("Close Refrigerator")
      H --> I(["Stop"])
      </pre>  
{% endraw %}

## Function Make Dough

{% raw %} 
  <pre class="mermaid">
    graph TD
        md[["Make Dough"]] --> A(["Start"])
        A --> C("Create Dough Object")
        C --> Initialization{{"Initialize spoon = 0"}} --> Condition{"spoon < 10"} --> Action("Add a spoon of flour to dough") --> Increment("spoon = spoon + 1") --> Condition
        Condition -- "No" --> D2("Add Water to Dough")
        D2 --> D3("Add Yeast to Dough")
        D3 --> D4("Add Salt to Dough")
        D4 --> Initialization2{{"Initialize spoon = 0"}} --> Condition2{"spoon < 3"} --> Action2("Add a spoon of Sugar to dough") --> Increment2("spoon = spoon + 1") --> Condition2
        Condition2 -- "No" --> E("Mix Ingredients")
        E --> F1("Stir until Combined")
        F1 --> F2("Beat until Smooth")
        F2 --> F3("Stir in Remaining Flour")
        F3 --> I(["Stop"])
      </pre>  
{% endraw %}
