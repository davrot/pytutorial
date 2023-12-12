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
    start([Start]) --> inita{{"counter ← 0"}} --> inita{{"counter_max ← 100"}} --> Condition{"counter < counter_max"}
    Condition -- Yes --> printcounter[/"print counter"/] --> Action["counter ← counter + 1"]
    Action --> Condition
    Condition -- No --> End(End)
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

