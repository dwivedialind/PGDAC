# Source Code Management(SCM)

## Version Control System(VCS):

**_VCS/SCM/Revision Control System(RCS) are software tools for keeping track of changes to code over time_**

- Developers can collaborate on different projects, separating their tasks through branches.
- Look back to earlier versions for comparing and fixing the mistakes if needed.

**_Version_**

- Copy of document taken at a specific time
- records
  - author
  - time stamp
  - changes

### Benefits of Using VCS

1. Long-term change history

   - Changes made by developers over the years, can be seen in history.
   - Allows going back to previous version for analyzing bugs and fixing problems.

2. Branching and Merging

   - (**Branching**)No interference with each other's work.
   - (**Merging**)Brings the work together and seeing if there are conflicts between those works.

3. Traceability

   - Trace each change and connect to project management or bug-tracking software.
   - Commits on message helps describing purpose of the change.

4. Synchronization
   - fetch up-to-date codes from repository
5. Backup and Restore
   - Files are saved at any time
   - Restored from last saved one
6. Undoing
   - Can undo last known version and last one created long time ago.

## Types of VCS

1. Local Version Control System
2. Centralized Version Control System
3. Distributed Version Control System

### Local VCS

**_Source Safe is one of obsolete Source Control System_**

1. Prevent data loss from modifications to the actual file content.

2. Avoid confusing directories

   - Directory Proliferation: Without VCS, you might create multiple directories to save different versions of your project. This become difficult to manage and remember which version is which.
   - Misplacement: Misplace files in wrong directory or forget which directory contains latest version of your files.

3. Prevent Accidental Overwrites and Misfiled Copies

   - Overwriting Files: While manually copy files to create a new version, might overwrite existing files accidentally, losing important changes.
   - Wrong Copies: Accidentally copy files to the wrong location, causing confusion about which files are most recent or which ones are correct.

4. Limitations:
   - Individual Use
   - No Collaboration
   - Single Point of Failure

### Centralized VCS

All versions of project stored in a single central repository(server).

1. Central Repository
   - All files and version at one central location
   - Acts as the **single source of truth** for the project.
2. Client-Server Model
   - Users get files from and send changes to central server.
3. How it Works:
   - Checkout: User gets a copy of project from central repository.
   - Edit: Users make changes to local copy.
   - Commit: Changes sent back to central repository.
   - Update: Users get latest changes from central repository.
4. Benefits
   - Centralized Management
   - Simplified Access Control
   - Collaborative
5. Challenges
   - Single Point of failure
   - Scalability Issues: Performance can suffer with large teams or projects.
   - Network Dependency: Requires network connection to interact with central repository.

**_SubVersion, PerForce, CVS(Concurrent Version System)_**

### Distributed VCS

1. Local Repository:
   - Every user has a complete copy of the entire repository, including all history.
   - Users can commit changes to their own local repositories without needing network access.
2. Peer-to-Peer Model:

   - Users can share changes directly with each other or synchronize with a central server if needed.

3. No Single Point of Failure:
   - Each user's local repository is a complete backup of the project.

**_Git, Mercurial, Bazaar or Darcs_**

## Git

- Designed and Developed by Linus Trovalds for Linux Kernel development
- Free software distributed under the terms of the GNU General Public License version 2

### Characteristics:

- Strong support for non-linear development **[Branches]**

- Distributed Development
- Compatibility with existent systems and protocols
- Efficient handling of large projects
- cryptographic authentication of history
- Toolkit-based design
- Pluggable merge strategies

### Advantages

- Free and open source
- Fast and Small
- Implicit backup
- Security
- No need of powerful hardware
- Easier Branching

### Git Workflow

![gitWorkflow](https://i.imgur.com/k4xNwE2.png)

1. **_git init_**

- Initialize a new empty Git repository or to reinitialize an existing one
- Repository is a directory which contains the working directory along with metadata in <code>.git</code>

```bash
# Get the current status of repository(working directory+ staging area)
> git status
# Get the status with short style
> git status -s
?? file.js
# status will be represented in two characters
# 1. status of file against the staging area
# 2. status of file against the working directory
```

> ?? -> The file is untracked (the file is not known to the repository or the repository has not yet created any version of this file)

2. **_Staging Area_**
   A temporary collection before you add your file to the repository.

```bash
# To add file from working directory to staging area
> git add <file_name>

> git status -s
A  file.js
# the changes to file are added to the staging area
```

3. **_git commit_**

- Committed snapshots are considered safe versions of a project because Git asks before changing them.

```bash
# commit the changes to the repository
# - any version in repository will contain
#       - author(user who has committed the changes)
#       - date and time of commit
#       - message used while committing the changes
#       - actual changes (added and deleted lines/files)
> git commit -m <commit_message>
```

4. **_git log_**

- shows committed snapshots
- only works on the committed history

```bash
> git log --oneline --color --graph

# --oneline: show only one line description
# --color: show colors while showing the logs
# --graph: show the branch graph
```

5. **_git status_**

```bash
# Modify the file.js
> git status -s
# _M: the file is modified and present in working directory

# add all the changes in the current directory to staging area
> git add .

> git status -s
# M_: the file is modified and present in staging area
```

6. **_git diff_**

- gets the difference of current version of file with last recorded version

7. **\*git checkout**

- if the last recorded version in staging area, then **git checkout** will restore to that version.
- else to last committed snapshot

```bash
#remove all the changes by replacing last recorded version with current version. You cannot retrieve the changes
> git checkout file.js

```

8. **_git reset_**

- if changes are staged **git checkout** won't work
- Unstage the changes

```bash
# remove the changes from staging area and move them back to working directory
> git reset

```

```bash
# unstage the changes and remove them immediately
# (along with all the changes in the working directory)
# Note: please execute this command on your own risk

> git reset --hard
```

### Git Internals

```bash
- git repository (.git directory)
    - HEAD
    - config
    - description
    - hooks
    - info
    - objects
        - on commit, git creates the objects(files) in this directory
        - there are 4 types of objects
            - commit object
                - created per commit
                - it contains the information
                    - tree object id
                    - author
                    - committer
                    - commit message
            - tree object
                - created per commit per directory
                - it contains the information
                    - 100644: the entry is pointing to a file
                    - blob: type of object
                    - blob object id: the id of blob object
                    - file name: the name of the file which is having the contents stored in the blob file
            - blob object
                - created per file
                - it contains the contents of a file in encrypted format ( use git cat-file command to read the contents)
    - refs
        - heads
            - points to latest commit id
        - tags
```

1. **_id's here are in the form of hash value_**

```bash
# get the contents of internal object
> git cat-file -p <object-id>
# object-id: <dir_name>+hash
# git cat-file -t 6b3a
```

2. **_if two files have same content then blob object will be same for them_**

3. **_After making changes to file and commit, the commit object contains <code>parentId</code> which is the previous version of <code>objectId</code>_**

### Git Branching

- A way to write code without affecting the rest of your team.
- Generally used for feature development.
- Once confirmed, can merge the branch in the master branch and release the build to customers.

1. Branch is a <code>file</code> under **_.git/refs/heads_** with branch name, which stores latest commit id.
2. Default branch name is either **_main or master_**

3. **_git branch_**

- Get list of branches

```bash
# create a branch
> git branch <branch_name>
# main and another created branch would point to same commit id
```

```bash
# to switch to branch
# git checkout <branchname>
> git branch b1
```

```bash
# create a new branch and checkout immediately
> git checkout -b b2
```

#### Merging

1. Merge new_branch in main

```bash
# merge b1 in main
> git checkout main
# show branch name
> git status
> git merge b1
```

2. Delete a branch

```bash
# delete a branch
> git branch -d <branch_name>
```

3.

```bash
> git push origin --delete <branch_name>
#deletes a branch from a remote repository after pushing any unpushed commits.

```

4.

```bash
> git log --graph --oneline --all --decorate

```

5. Checkout to commit id

```bash
> git checkout <commit_id>
```
