# 🧠 Threading and Philosophy Project

## 📚 Project Overview
In this project, you'll learn the basics of threading a process. You'll explore how to create threads and discover mutexes. 

## 🧐 What is Philosophy?
**Philosophy** (from Greek, *philosophia*, literally "love of wisdom") is the study of fundamental questions about existence, knowledge, values, reason, mind, and language. Key points include:

- **Origins**: The term was likely coined by **Pythagoras** (c. 570 – 495 BCE).
- **Methods**: Philosophical methods include questioning, critical discussion, rational argument, and systematic presentation.
- **Classic Questions**:
  - Is it possible to know anything and prove it?
  - What is most real?
  - Is there a best way to live?
  - Is it better to be just or unjust (if one can get away with it)?
  - Do humans have free will?

### 📜 Historical Context
Historically, "philosophy" encompassed any body of knowledge. From **Aristotle** to the 19th century, "natural philosophy" included astronomy, medicine, and physics. For example, Newton's *Mathematical Principles of Natural Philosophy* later became classified as a book of physics.

In the 19th century, modern research universities led to the professionalization and specialization of academic philosophy. Some investigations, such as psychology, sociology, linguistics, and economics, became separate disciplines, while others remained part of philosophy.

### 🔍 Major Sub-fields
- **Metaphysics**: Fundamental nature of reality and being.
- **Epistemology**: Nature and limits of knowledge.
- **Ethics**: Moral principles.
- **Aesthetics**: Nature of beauty and art.
- **Political Philosophy**: Study of government and justice.
- **Logic**: Principles of valid reasoning.
- **Philosophy of Science**: Examination of scientific methods.

---

## ⚙️ Common Instructions

### 📜 Project Requirements
- **Language**: C
- **Norm Compliance**: Following the Norm.
- **Error Handling**: Functions not quit unexpectedly (segmentation fault, bus error, etc.). All heap-allocated memory is freed.
- **Makefile Requirements**:
  - Compile with flags `-Wall`, `-Wextra`, and `-Werror`.
  - Include rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

---

## 🎯 Description
This project simulates philosophers using threads and mutexes, ensuring they can eat without starving while managing shared resources safely.

---

### 📅 Overview of the Simulation
![Alt text](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRq_hLVm862_Z0oa6lsP_0JMT9xfmjRXJ3BJ_Z57vnziDLG2QDN5kCtvrQ44DufeOkEmGY&usqp=CAU)

- **Philosophers at the Table**: 
  - One or more philosophers sit at a round table with a bowl of spaghetti.
  - They alternate between eating, thinking, and sleeping.
  - Each philosopher uses both the left and right forks to eat.

### 🍴 Forks and Eating
- There are as many forks as philosophers.
- Once finished eating, philosophers return the forks and sleep until they wake to think again.
- The simulation ends when a philosopher dies of starvation.
  
---

### ⚠️ Remember!
Philosophers should avoid dying! 😅

### 🚫 Global Rules
- **Don't use Global Variables**:
- **Program Arguments**:
  - `number_of_philosophers`
  - `time_to_die` (milliseconds)
  - `time_to_eat` (milliseconds)
  - `time_to_sleep` (milliseconds)
  - `[number_of_times_each_philosopher_must_eat]` (optional)

### 📜 Logging Format
Any state change of a philosopher must be formatted as follows:
- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

### 🛠️ Mandatory Part
- **Program Name**: `philo`
- **Files**: `Makefile`, `*.h`, `*.c` in the `philo/` directory.
- **External Functions**: Use `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`.

# 📖 Usage of the Philosophers Project

## 🛠️ Getting Started

To run the project, follow these steps:

### 1. Clone the Repository

First, clone the repository to your local machine:

```bash
git@github.com:mel-harc/PHILOSOPHORS-DINNING.git
cd philosophers
cd philo
```
### 2. Compile the Project

Use the provided Makefile to compile the project:

```bash
make
```

### 3. Run the Simulation

You can run the simulation with the following command:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

## 📊 Example Commands

Here are a few example commands to run the simulation:

- Example 1: Five philosophers, each having 800 milliseconds to eat, 200 milliseconds to sleep, and they will die if they don't eat within 800 milliseconds.

```bash
./philo 5 800 200 200
```

- Example 2: Three philosophers, with an optional argument specifying that each should eat at least 5 times.

```bash
./philo 3 800 200 200 5
```


Sure! Here's an example of how you might document the usage of your project in Markdown:

markdown
Copier le code
# 📖 Usage of the Philosophers Project

## 🛠️ Getting Started

To run the project, follow these steps:

### 1. Clone the Repository

First, clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/philosophers.git
cd philosophers
```
2. Compile the Project
Use the provided Makefile to compile the project:

```bash
make
```
3. Run the Simulation
You can run the simulation with the following command:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

## 📊 Example Commands

Here are a few example commands to run the simulation:

Example 1: Five philosophers, each having 800 milliseconds to eat, 200 milliseconds to sleep, and they will die if they don't eat within 800 milliseconds.

```bash
./philo 5 800 200 200
```
Example 2: Three philosophers, with an optional argument specifying that each should eat at least 5 times.

```bash
./philo 3 800 200 200 5
```

## 📝 Important Notes

  - Ensure that your arguments are in the correct format, or the simulation will not run correctly. 
  - Each philosopher will be represented by a number from 1 to number_of_philosophers.
  - Pay attention to the log messages to understand the state changes of each philosopher.

## 📸 Example Output

When you run the simulation, you might see output like this:

```bash
1000 1 has taken a fork
1000 1 is eating
1100 1 is sleeping
...
1200 1 died
```

This output shows the timestamps and the actions of each philosopher throughout the simulation.

## by mel-harc

  
