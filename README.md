# Summarize the project and what problem it was solving.
Item-tracking program for the Corner Grocer to analyze daily purchase records. 
The goal is to help the store understand how often items are bought so they can optimize their store layout.

# What did you do particularly well?
One of the strongest aspects of this project is the use of a map<string, int> to efficiently store and retrieve item frequencies. This ensures:
- Fast lookups (logarithmic time)
- Automatic sorting of keys for clean output

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
Adding comments or documentation for each method would help future developers understand the intent quickly.

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
Histogram formatting because it required careful use of setw and string construction to align output properly.

# What skills from this project will be particularly transferable to other projects or course work?
File I/O handling- reading/writing structured data
Input validation and error handling
Modular design using classes

# How did you make this program maintainable, readable, and adaptable?
Clear function responsibilities -Each method has a single, well-defined purpose
Simple control flow- The menu loop is easy to follow and modify
