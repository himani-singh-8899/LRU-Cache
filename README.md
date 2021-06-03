# Why Use A Cache?
Say you're managing a cooking site with lots of cake recipes. As with any website, you want to serve up pages as fast as possible.
When a user requests a recipe, you open the corresponding file on disk, read in the HTML, and send it back over the network. This works, but it's pretty slow, since accessing disk takes a while.
Ideally, if lots of users request the same recipe, you'd like to only read it in from disk once, keeping the page in memory so you can quickly send it out again when it's requested. Bam. You just added a cache.
A cache is just fast storage. Reading data from a cache takes less time than reading it from something else (like a hard disk).
Here's the cache catch: caches are small. You can't fit everything in a cache, so you're still going to have to use larger, slower storage from time to time.
If you can't fit everything in the cache, how do you decide what the cache should store?

# Some requirements are
Fixed Size: Cache needs to have some bounds to limit memory usages.
Fast Access: Cache Insert and lookup operation should be fast , preferably O(1) time.
Replacement of Entry in case , Memory Limit is reached: A cache should have efficient algorithm to evict the entry when memory is full.

# LRU-Cache
You have given a cache (or memory) capacity. The cache will be filled with items you will access or look for it. The most recently accessed item will be at the top of the cache whereas the least recently used cache will be at the end of the cache. As you will access the items, the cache will be filled as per the conditions below
If the item is not present in the cache and cache capacity is NOT REACHED then the item will be added at top of the cache.
f the item is not present in the cache and cache capacity is REACHED then least recently item from cache will be removed (the last element in cache) and a new item will be added at top of the cache.
If the item is already present in the cache then it will be moved to the top of the cache.

# Using HashMap and Doubly Linked List:
Doubly Linked List: For each item, we will create a Node for a doubly-linked list. The Node will have item value and next and previous node references. The list will represent the cache and order. So each time item will be referred or looked or accessed the nodes in the list will change the orders accordingly. Click here to read about Doubly Linked List.

HashMap: Map will be used to check if the item is present in the cache in O(1) time. In key-value pairs, the item will be the key and Node (doubly linked list node) will be its value. Every time item becomes the part of a cache, we will put that item in the map as well and vice versa, when the item is deleted from the cache, we will delete it from the map.

# Strengths And Weaknesses
Strengths:
Super fast accesses. LRU caches store items in order from most-recently used to least-recently used. That means both can be accessed in O(1)O(1) time.

Super fast updates. Each time an item is accessed, updating the cache takes O(1)O(1) time.

Weaknesses
Space heavy. An LRU cache tracking nn items requires a linked list of length nn, and a hash map holding nn items. That's O(n)O(n) space, but it's still two data structures (as opposed to one).
