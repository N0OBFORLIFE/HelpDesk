# HelpDesk

[Presentation video](https://drive.google.com/file/d/1l7Apa3-oPMey8kOATSfdib_sKRAU1bF2/view?usp=drivesdk)

Header files adapted from the [Template](https://github.com/AlproITS/StrukturData/tree/master/For%20C/D.Array%2C%20Stack%2C%20Queue%2C%20Deque%2C%20Pr.Queue) C files; deque_list.c, queue_array.c, stack_array.c

[Click here](https://github.com/N0OBFORLIFE/HelpDesk/tree/main/src) for the report

## Features
- **Urgency handling**: uses a **deque** (doubly linked list)
- **Normal Queue**: uses a circular array **queue**
- **Solved History**: uses a **stack** to track solved tickets and allows the undo feature to exist

## How To Run
1. Clone the repository
2. Get to the `src` folder which has the relevant files
3. Compile with GCC and run:
```bash
gcc main.c -o main && ./main
```
(run main in the next command if error)
