## Database Concepts

**_MySQL v5.7 (RDBMS)_**
**_Oracle 11g(ORDBMS)_**
**_MongoDB (NoSQL DBMS)_**

- DBMS(**Database Management System**): Software that helps to manage data

```bash
Various DBMS available
MSExcel, FoxBASE, FoxPro, DataEase, DataFlex, Clipper, DB Vista etc
```

#### Some Important Definitions

1. RDBMS: Relational Database Management System
2. ORDBMS: Object Relational DBMS (RDBMS+OODBMS)
3. OODBMS: Object Oriented DBMS
4. Database: Collection of Large amounts of data.
5. **_ANSI definition of DBMS_** : collection of programs that allows you to perform CRUD operations of data.

- **_Computer_**: Processing(work done by computer) raw data to meaningful data/ processed data/ information.

### DBMS vs RDBMS

1. Difference in Nomenclature

   - Field - attribute/column
   - Record - tuple/row/entity
   - File - table/relation

2. Relationship between two file is maintained programmatically.
   vs
   Relationship between 2 tables can be specified at the time of table creation using constraint.

3. More Programming
   vs
   Less Programming

4. More time required for s/w development
   vs
   Less time require for s/w development

> Let's take an example of Server with Employee data is located in Delhi and Client in Pune,
> Now In DBMS to access Employees with Salary > $1000, we have to copy files to Pune then after processing, send the data back to Delhi (Server location)
> vs
> In RDBMS we can process data on server only.

5. High Network Traffic
   vs
   Low Network Traffic

6. Slow & expensive
   vs
   Faster (in terms of network speed) and cheaper (in terms of hardware cost, network cost, infrastructure cost)

7. Processing on Client Machine
   vs
   Processing on Server Machine(**Client-Server Architecture**)

> Most of the RDBMS Support Client-Server Architecture. (exception is MS Access->**local Database on same machine**)

8. File level Locking(**not suitable for multi-user**)
   vs
   Row level Locking(internally table is not a file, internally every row is a file)

> Suppose there is a Server located in Delhi, with **_Pune_** and **_Hyderabad_** as client, now in DBMS is **_Pune_** tries to update any table in Server then that table is locked for **_Hyderabad_**
> vs
> In RDBMS only row is locked .

9. Distributed databases not supported
   vs
   Most of the RDBMS support Distributed Databases (**Banking system is an example of Distributed Databases**)

10. No security (of data)
    - DBMS is dependent of OS for security
    - DBMS allows access to the data through the OS
    - Security is not a built-in feature of DBMS
      vs
      Multiple Levels of Security
    - Logging in Security (MySQL database username and password)
    - Command level Security (permission to issue MySQL commands)
      - create table, create function, create user, etc
    - Object level Security (access to table and objects of other users)

![HowServerOSDifferentFromClientOS](https://i.imgur.com/mm9QaKO.png)

- Various RDMBS available:
  - Informix (fastest in terms of processing speed)
  - Oracle (most popular RDBMS)
    - works on 113 OS
    - 63% of world commercial DB market in Client-Server Environment
    - 86% of world commercial DB market in the Internet Environment
  - Sybase (Good RDBMS)
  - MS SQL Server
    - Only works with Windows OS
  - MS Access (Single User)
  - DB2 (MainFrame Computer from IBM)
  - Postgres (Open source)

**_ Our Focus will be on MySQL _**

## MySQL

1. Launched by Swedish company in 1995.
2. MySQL is a open-source RDBMS (most widely used open-source RDBMS).
3. Part of **\*LAMP** open-source web-development.
4. Sun Microsystems acquired MySQL in 2008
5. Oracle Corporation acquired Sun Microsystems in 2010.

```bash
L - Linux
A - Apache Web Server
M - MySQL
P - Perl, Python or PHP
```

### Various S/W development tools from MySQL

1. MySQL Command Line Client (client S/W)
   - Used for running SQL commands
   - Character based (text based)
   - Interface with database
2. MySQL Workbench (client S/W)
   - Used for running SQL commands
   - GUI based interface with database
3. MySQL Pl
   - MySQL Programming Language
   - Used for database Programming
4. MySQL Connectors
   - for database connectivity (JDBC, ODBC, Python, C, C++ etc)
5. MySQL for Excel
   - import, export, and edit MySQL data using MS Excel
6. MySQL Notifier
   - Start-up and Shutdown the MySQL database
7. MySQL Enterprise Backup
   - export and import of table data
   - used to take backups and restore from the backups
8. MySQL Enterprise High Availability
   - for replication (also know as data mirroring) concept of standby database
9. MySQL Enterprise Encryption
   - used to encrypt table data
10. MySQL Enterprise Manager
    - for performance monitoring, and performance tuning
11. MySQL Query Analyzer
    - for query tuning

### SQL

- Structured Query Language
- Commonly pronounced as "Sequel"
- conforms to ANSI standards (e.g 1 character = 1 Byte)
- Conforms to ISO standards (for QA)
- Common for all RDBMS(hence also known as RDBMS)
- Initially founded by IBM (1975-77)
- Initially known as RQBE (Relational Query by Example)
- IBM gave RQBE free of cost to ANSI
- ANSI renamed RQBE to SQL (Now, controlled by ANSI6)
- In 2005, source code of SQL was rewritten in Java(100%)

> **_Every row in Table is a file, Table is not a file which helps us achieve row-level locking._**

#### Divisions of SQL

1. DDL (Data Definition Language): Create, Drop, Alter
2. DML (Data Manipulation Language): Insert, Update, Delete
3. DCL (Data Control Language): Grant, Revoke
4. DQL (Data Query Language): Select

```bash
Extra in Oracle RDBMS and MySQL
1. DTL/TCL (Data Transaction Language)/(Transaction Control Language)
    Commit, Rollback, Savepoint
2. DDL
    Rename, Truncate

Extra in Oracle RDBMS only:
1. DML
    (Merge, Upsert(Update+Insert))
```

**_Rules for Table Names, columns names and variable names_**

- Oracle: Max 30 characters MySQL: Max 64 characters
- A-Z, a-z, 0-9 allowed
- Has to begin with an alphabet
- Special characters, $, #, \_ allowed
- In MySQL to use reserved characters such as <code>#</code> int tableName and column Name, enclose it in backquotes(``).
`EMP#`
- 134 reserved words not allowed

> **_Under Linux & Unix, table_name and column_name are case-sensitive. But in Windows & macos are not case-sensitive_**
