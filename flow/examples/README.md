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
