# Python Scopes and Namespaces
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

Shortened quotes from [https://docs.python.org/3/tutorial/classes.html](https://docs.python.org/3/tutorial/classes.html)

## [Scopes and Namespaces Example](https://docs.python.org/3/tutorial/classes.html#scopes-and-namespaces-example)

> This is an example demonstrating how to reference the different scopes and namespaces, and how [global](https://docs.python.org/3/reference/simple_stmts.html#global) and [nonlocal](https://docs.python.org/3/reference/simple_stmts.html#nonlocal) affect variable binding:


```python
def scope_test():
    def do_local():
        spam = "local spam"

    def do_nonlocal():
        nonlocal spam
        spam = "nonlocal spam"

    def do_global():
        global spam
        spam = "global spam"

    spam = "test spam"
    do_local()
    print("After local assignment:", spam) # -> After local assignment: test spam
    do_nonlocal()
    print("After nonlocal assignment:", spam) # -> After nonlocal assignment: nonlocal spam
    do_global()
    print("After global assignment:", spam) # -> After global assignment: nonlocal spam

scope_test()
print("In global scope:", spam) # -> In global scope: global spam
```

> Note how the local assignment (which is default) didn’t change scope_test's binding of spam. The nonlocal assignment changed scope_test's binding of spam, and the global assignment changed the module-level binding.

> You can also see that there was no previous binding for spam before the global assignment.


Shortened quotes from  [https://docs.python.org/3/tutorial/classes.html](https://docs.python.org/3/tutorial/classes.html)

> **Namespaces** are created at different moments and have different lifetimes. The namespace containing the built-in names is created when the Python interpreter starts up, and is never deleted. The global namespace for a module is created when the module definition is read in; normally, module namespaces also last until the interpreter quits.
>
> The **local namespace** for a function is created when the function is called, and deleted when the function returns or raises an exception that is not handled within the function.
>
> A **scope** is a textual region of a Python program where a namespace is directly accessible.
> 
> Although scopes are determined statically, they are used dynamically. At any time during execution, there are 3 or 4 nested scopes whose namespaces are directly accessible:​
> * the innermost scope, which is searched first, contains the local names
> * the scopes of any enclosing functions, which are searched starting with the nearest enclosing scope, contains non-local, but also non-global names
> * the next-to-last scope contains the current module’s global names
> * the outermost scope (searched last) is the namespace containing built-in names


## [The global statement](https://docs.python.org/3/reference/simple_stmts.html#the-global-statement)

```python
global_stmt ::=  "global" identifier ("," identifier)*
```

> The global statement is a declaration which holds for the entire current code block. It means that the listed identifiers are to be interpreted as globals. It would be impossible to assign to a global variable without global, although free variables may refer to globals without being declared global.
> 
> Names listed in a global statement must not be used in the same code block textually preceding that global statement.

> **Programmer’s note**: global is a directive to the parser. It applies only to code parsed at the same time as the global statement. In particular, a global statement contained in a string or code object supplied to the built-in exec() function does not affect the code block containing the function call, and code contained in such a string is unaffected by global statements in the code containing the function call. The same applies to the eval() and compile() functions.

## [The nonlocal statement](https://docs.python.org/3/reference/simple_stmts.html#nonlocal)

```python
nonlocal_stmt ::=  "nonlocal" identifier ("," identifier)*
```

> The nonlocal statement causes the listed identifiers to refer to previously bound variables in the nearest enclosing scope excluding globals. This is important because the default behavior for binding is to search the local namespace first. The statement allows encapsulated code to rebind variables outside of the local scope besides the global (module) scope.
> 
> Names listed in a nonlocal statement, unlike those listed in a global statement, must refer to pre-existing bindings in an enclosing scope (the scope in which a new binding should be created cannot be determined unambiguously).
> 
> Names listed in a nonlocal statement must not collide with pre-existing bindings in the local scope.


 
