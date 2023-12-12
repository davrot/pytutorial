


{% raw %} 

  <pre class="mermaid">
    graph TD
    A(["Start"]) --> B{"Ingredients Ready?"}
    B -->|"Yes"| C["Preheat Oven"]
    B -->|"No"| D[["Gather Ingredients"]]]
    D --> C
    C --> md[["Make Dough"]] --> E["Knead Dough"]
    E --> F{"First Rise Complete?"}
    F -->|"Yes"| G["Punch Down Dough"]
    F -->|"No"| E
    G --> H["Shape Loaf"]
    H --> I{"Second Rise Complete?"}
    I -->|"Yes"| J["Bake"]
    I -->|"No"| H
    J --> K(["Stop"])
  </pre>  
  
  <pre class="mermaid">
    graph TD
      gi[["Gather Ingredients"]] --> A(["Start"]) --> B["Go to Kitchen"]
      B --> C["Open Pantry"]
      C --> D1["Get Flour"]
      D1 --> D2["Get Sugar"]
      D2 --> D3["Get Salt"]
      D3 --> E["Close Pantry"]
      E --> F["Open Refrigerator"]
      F --> G1["Get Water"]
      G1 --> G2["Get Yeast"]
      G2 --> H["Close Refrigerator"]
      H --> I(["Stop"])
      </pre>  

  <pre class="mermaid">
    graph TD
        md[["Make Dough"]] --> A(["Start"]) -->
        B --> C["Create Dough Object"]
        C --> D1["Add Flour to Dough"]
        D1 --> D2["Add Water to Dough"]
        D2 --> D3["Add Yeast to Dough"]
        D3 --> D4["Add Salt to Dough"]
        D4 --> D5["Add Sugar to Dough"]
        D5 --> E["Mix Ingredients"]
        E --> F1["Stir until Combined"]
        F1 --> F2["Beat until Smooth"]
        F2 --> F3["Stir in Remaining Flour"]
        F3 --> I(["Stop"])
      </pre>  
{% endraw %}
