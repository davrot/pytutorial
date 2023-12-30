# [set](https://docs.python.org/3/library/stdtypes.html#set) and [frozenset](https://docs.python.org/3/library/stdtypes.html#frozenset)
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

{: .topic-optional}
This is an optional topic!

# [Set Types — set, frozenset](https://docs.python.org/3/library/stdtypes.html#set-types-set-frozenset)

> A set object is an unordered collection of distinct hashable objects. Common uses include membership testing, removing duplicates from a sequence, and computing mathematical operations such as intersection, union, difference, and symmetric difference.
> 
> Like other collections, sets support x in set, len(set), and for x in set. Being an unordered collection, sets do not record element position or order of insertion. **Accordingly, sets do not support indexing, slicing, or other sequence-like behavior.**
> 
> There are currently two built-in set types, set and frozenset. 
> * The **set type is mutable** — the contents can be changed using methods like add() and remove(). Since it is mutable, it has no hash value and cannot be used as either a dictionary key or as an element of another set.
> * The **frozenset type is immutable and hashable** — its contents cannot be altered after it is created; it can therefore be used as a dictionary key or as an element of another set.


```python
class set([iterable])
class frozenset([iterable])
```

> Return a new set or frozenset object whose elements are taken from iterable. The elements of a set must be hashable. To represent sets of sets, the inner sets must be frozenset objects. If iterable is not specified, a new empty set is returned.
> 
> Sets can be created by several means:
> * Use a comma-separated list of elements within braces: {'jack', 'sjoerd'}
> * Use a set comprehension: {c for c in 'abracadabra' if c not in 'abc'}
> * Use the type constructor: set(), set('foobar'), set(['a', 'b', 'foo'])

Instances of **set and frozenset** provide the following operations:

|||
|---|---|
|len(s)|Return the number of elements in set s (cardinality of s).|
|x in s|Test x for membership in s.|
|x not in s|Test x for non-membership in s.|
|isdisjoint(other)|Return True if the set has no elements in common with other. Sets are disjoint if and only if their intersection is the empty set.|
|issubset(other)|Test whether every element in the set is in other.|
|set <= other|Test whether every element in the set is in other.|
|set < other|Test whether the set is a proper subset of other, that is, set <= other and set != other.|
|issuperset(other)|Test whether every element in other is in the set.|
|set >= other|Test whether every element in other is in the set.|
|set > other|Test whether the set is a proper superset of other, that is, set >= other and set != other.|
|union(*others)|Return a new set with elements from the set and all others. |
|set \| other \| ...|Return a new set with elements from the set and all others. |
|intersection(*others)|Return a new set with elements common to the set and all others.|
|set & other & ...|Return a new set with elements common to the set and all others.|
|difference(*others)|Return a new set with elements in the set that are not in the others.|
|set - other - ...|Return a new set with elements in the set that are not in the others.|
|symmetric_difference(other)|Return a new set with elements in either the set or other but not both.|
|set ^ other|Return a new set with elements in either the set or other but not both.|
|copy()|Return a shallow copy of the set.|


The following table lists operations **available for set** that do not apply to immutable instances of frozenset:

|||
|---|---|
| update(*others)| Update the set, adding elements from all others. |
| set \|= other \| ... | Update the set, adding elements from all others.|
| intersection_update(*others) | Update the set, keeping only elements found in it and all others.|
| set &= other & ... | Update the set, keeping only elements found in it and all others.|
|difference_update(*others)| Update the set, removing elements found in others. |
|set -= other \| ...| Update the set, removing elements found in others.|
|symmetric_difference_update(other)|Update the set, keeping only elements found in either set, but not in both.|
|set ^= other|Update the set, keeping only elements found in either set, but not in both.|
|add(elem)|Add element elem to the set.|
|remove(elem)|Remove element elem from the set. Raises KeyError if elem is not contained in the set.|
|discard(elem)|Remove element elem from the set if it is present.|
|pop()|Remove and return an arbitrary element from the set. Raises KeyError if the set is empty.|
|clear() | Remove all elements from the set.|



