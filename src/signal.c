/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** signal
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int recep_sig = 0;

static void handler(int sig, siginfo_t *info, void *ucontext)
{
    if (sig == SIGUSR1)
        recep_sig = 1;
    if (sig == SIGUSR2)
        recep_sig = 0;
    kill(info->si_pid, SIGUSR1);
}

static void handler_return(int sig, siginfo_t *info, void *ucontext)
{
    if (sig == SIGUSR1)
        recep_sig += 1;
}

char *clean_bin(char *bin)
{
    int len = my_strlen(bin);

    for (; len >= 0; len--) {
        if (bin[len] == '0' && bin[len - 1] == '1') {
            bin[len] = 0;
            return (bin);
        }
    }
    return (bin);
}

int get_signal(void)
{
    struct sigaction act;
    int i = 0;
    char *bin = malloc(sizeof(char)*5);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &handler;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    while (i < 4) {
        pause();
        bin[i] = recep_sig + '0';
        i++;
    }
    bin[4] = 0;
    bin = clean_bin(bin);
    return (my_btoi(my_revstr(bin)));
}

void my_send_sig(int data, int pid)
{
    struct sigaction act;
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &handler_return;
    recep_sig = 0;
    sigaction(SIGUSR1, &act, NULL);
    for (; recep_sig <= 3;) {
        if ((data >> recep_sig) % 2 == 1)
            kill(pid, SIGUSR1);
        if ((data >> recep_sig) % 2 == 0)
            kill(pid, SIGUSR2);
        usleep(500);
    }
}