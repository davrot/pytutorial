# Flowchart examples
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Looking into some flow chart examples.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Most simple program

This program does nothing. 

{% raw %} 
  <pre class="mermaid">
    flowchart TD
      start([Start])-->stop([Stop])
  </pre>
{% endraw %}

In Python:

```python
pass
```

## a+b=c

{% raw %} 
  <pre class="mermaid">
    flowchart TD
      start([Start]) --> inita{{"a ← 1"}} --> initb{{"b ← 1"}} --> add("c ← a+b") --> printc[/"print c"/] -->stop([Stop])
  </pre>
{% endraw %}

In Python:

```python
a=1
b=1
c=a+b
print(c)
```

## a+b=c with input from user

{% raw %} 
  <pre class="mermaid">
    flowchart TD
      start([Start]) --> inputa[/"Input integer a"/] --> inputb[/"Input integer b"/] --> add("c ← a+b") --> printc[/"print c"/] -->stop([Stop])
  </pre>
{% endraw %}

In Python:

```python
a = int(input())
b = int(input())
c = a + b
print(c)
```

## for-loop / while loop

{% raw %} 
  <pre class="mermaid">
    flowchart TD
    start([Start]) --> initcounter{{"counter ← 0"}} --> initcountermax{{"counter_max ← 100"}} --> Condition{"counter < counter_max"}
    Condition -- Yes --> printcounter[/"print counter"/] --> Action["counter ← counter + 1"]
    Action --> Condition
    Condition -- No --> stop([Stop])
  </pre>
{% endraw %}

In Python:

```python
counter_max = 100
for counter in range(0, counter_max):
    print(counter)
```

or

```python
counter = 0
counter_max = 100
while counter < counter_max:
    print(counter)
    counter += 1
```

## if, elif, else

{% raw %} 
  <pre class="mermaid">
    flowchart TD
    start([Start]) --> inputa[/"Input integer a"/] --> Condition1{"a < 1"}
    Condition1 -- Yes --> Action1[/"print condition 1"/]
    Condition1 -- No --> Condition2{"a == 2"}
    Condition2 -- Yes --> Action2[/"print condition 2"/]
    Condition2 -- No --> ElseAction[/"print condition else"/]
    Action1 --> stop([Stop])
    Action2 --> stop
    ElseAction --> stop
  </pre>
{% endraw %}

In Python:

```python
a = int(input())
if a < 1:
    print("condition 1")
elif a == 2:
    print("condition 2")
else: 
    print("condition else")
```

## if, elif, else

{% raw %} 
  <pre class="mermaid">
    flowchart TD
    start([Start]) --> inputa[/"Input integer a"/] --> Condition1{"a < 1"}
    Condition1 -- Yes --> Action1[/"print condition 1"/]
    Condition1 -- No --> Condition2{"a == 2"}
    Condition2 -- Yes --> Action2[/"print condition 2"/]
    Condition2 -- No --> ElseAction[/"print condition else"/]
    Action1 --> stop([Stop])
    Action2 --> stop
    ElseAction --> stop
  </pre>
{% endraw %}

In Python:

```python
a = int(input())
if a < 1:
    print("condition 1")
elif a == 2:
    print("condition 2")
else: 
    print("condition else")
```

## functions

{% raw %} 
  <pre class="mermaid">
    flowchart TD
    Start([Start]) --> Input[/"Input integer a"/]
    Input -- a < 1 --> Function1[["function_1()"]]
    Function1 --> End([Stop])
    Input -- a == 2 --> Function2[["function_2()"]] --> End
    Input -- else --> FunctionElse[["function_else()"]] --> End
  </pre>

  <pre class="mermaid">
    flowchart TD
    Function1[["function_1()"]] --> Start([Start]) --> Print[/print("condition 1")/] --> End([Stop])
  </pre>

  <pre class="mermaid">
    flowchart TD
    Function2[["function_2()"]] --> Start([Start]) --> Print[/print("condition 2")/] --> End([Stop])
  </pre>

  <pre class="mermaid">
    flowchart TD
    FunctionElse[["function_else()"]] --> Start([Start]) --> Print[/print("condition else")/] --> End([Stop])
  </pre>
      
{% endraw %}

In Python:

```python
def function_1():
    print("condition 1")

def function_2():
    print("condition 2")

def function_else():
    print("condition else")

a = int(input())
if a < 1:
    function_1()
elif a == 2:
    function_2()
else: 
    function_else()
```
