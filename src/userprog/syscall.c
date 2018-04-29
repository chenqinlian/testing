#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

#define MAX_ARGS 4

static void syscall_handler (struct intr_frame *);
int user_to_kernel_ptr(const void *vaddr);
int process_add_file (struct file *f);
struct file* process_get_file (int fd);
void process_close_file (int fd);



void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f) 
{

  printf ("system call!\n");

  int i, arg[MAX_ARGS];
  for (i = 0; i < MAX_ARGS; i++)
    {
      arg[i] = * ((int *) f->esp + i);
    }

 
  printf ("system call! syscall number is : %d, ", arg[0]);

  switch(arg[0])
  {
    case SYS_HALT:
      printf("SYS_HALT\n");
      break;
    case SYS_EXIT:
      printf("SYS_EXIT\n");
      break;
    case SYS_EXEC:
      printf("SYS_EXEC\n");
      break;
    case SYS_WAIT:
      printf("SYS_WAIT\n");
      break;
    case SYS_CREATE:
      printf("SYS_CREATE\n");
      break;
    case SYS_REMOVE:
      printf("SYS_REMOVE\n");
      break;
    case SYS_OPEN:
      printf("SYS_OPEN\n");
      break;
    case SYS_FILESIZE:
      printf("SYS_FILESIZE\n");
      break;
    case SYS_READ:
      printf("SYS_READ\n");
      break;
    case SYS_WRITE:
      printf("SYS_WRITE\n");
      break;
    case SYS_SEEK:
      printf("SYS_SEEK\n");
      break;
    case SYS_TELL:
      printf("SYS_TELL\n");
      break;
    case SYS_CLOSE:
      printf("SYS_CLOSE\n");
      break;
  }
  thread_exit ();
}
