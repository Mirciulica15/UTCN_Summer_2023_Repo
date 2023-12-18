# Advanced Version Control

Once teams grow, it becomes hard to have many people working full-time on the same version control repository.

There are 3 good reasons to **branch** your code:

1. A branch can be created for releasing a new version of your application; this allows devs to work on new features without affecting the stable public release
2. When you need to spike out a new feature or a refactoring; the spike branch is thrown away and is never merged
3. Creating a short-lived branch when you need to make a large change to the applicatoin that is not possible with any other methods (rare if codebase is structured well)

## History of VCS

### Subversion (SVN)

- first steps
- does not support offline committing
- revision is done at repository level, not at file level
- non-distributed

### Switch Off Pessimistic Locking

- don't lock local files
- it does prevent merge conflicts, but diminishes productivity
- instead, use **optimistic** locking
- optimistic locking works at line level in source code; if A changes line 5 and B changes line 6, we keep both changes; if A and B both change line 7, there is a **conflict**
- the only time pessimistic locking makes sense is when dealing with images or documents

## Branching and Merging

### Branching 

- it is common to branch on release, allowing for ongoing development on mainline and bugfixing in the release branch
- there are several reasons for branching:

  - physical: for components, subsystems
  - functional: for features, logical changes, bugfixes, enhancements, paches, releases, products, etc
  - environmental: for the system's operating environment (compilers, windowing systems, libraries, hardware, OS, etc)
  - organizational: for the team's efforts, activities, tasks, subprojects
  - procedural: for the team's work behaviors, policies, processes, states
 
- these categories aren't mutually exclusive
- the problem is that branches often have to **interact** with each other => **merging**
- it's important to **think carefully** before branching and to have **sensible process** to support it
- define a **policy** for every branch describing its role in the delivery process and prescribe who is allowed to check in and under what circumstances

### Merging

- the real problem arises when two different and conflicting changes have been made in branches you want to merge
- your VCS will detect overlapping changes and warn you
- however, conflicts may be **missed** by the revision control system; ex: differences in intent (conflicting implementation of the same functionality) => **conversations** have to happen
- **semantic** conflicts that are not caught can be some of the most pernicious; ex: Kate performs a refactoring that renames a class and Dave makes a reference to the class (old name), this will not be detected
- there are ways of minimizing this pain:

  - create more branches to reduce the number of changes made to a given branch; this is an example of **"early branching"**; however, more branches means more work to keep track of them and more merges
  - avoid creating branches, perhaps creating a branch per release; this is an exmaple of **deferred branching**; to minimize the pain of merging, do it often (every day, for example)
 
### Branches, Streams and Continuous Integration

- a manageable branching **strategy**, industry standard (at the time of writing), is to create **long-lived** branches only on release

![image](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/883b71d4-cb6a-4c04-9bdf-a540ace0405a)

- in this model, new work is always committed to the **trunk**
- merging is only performed when a fix has to be made to the release branch, from which it is then merged into mainline
- critical bugfixes might also be merged from mainline into release branches
- this model is good because the code is always **ready** to be released; there are also fewer branches

### Best Practices

- we can have even 200 merges a day if the codebase is structured correctly
- however, if multiple developers have to touch the same bits of code, this is a sign of a poorly structured architecture with insufficient encapsulation and high coupling
- things are much worse if merges are left until the end of the release
- **split** your application into components and ensure **loose coupling**
- you should **never use long-lived, infrequently merged branches**

## Distributed Version Control Systems

























