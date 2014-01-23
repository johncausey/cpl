//
// Backup program to run as process and end on complete.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

static void build_daemon();

int main() {

	// Build daemon to use
	build_daemon();

	while (1) {
		syslog (LOG_NOTICE, "Backup process has started.");
		sleep (25); // Call backup stuff
		break;
	}

	syslog (LOG_NOTICE, "Backup process has stopped.");
	closelog();

	return EXIT_SUCCESS;
}

static void build_daemon() {
	pid_t pid;
	pid = fork(); // Fork off the parent process

	// Exit error if error, let parent terminate if success
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid > 0)
		exit(EXIT_SUCCESS);

	// On success: The child process becomes session leader
	if (setsid() < 0)
		exit(EXIT_FAILURE);

	// Catch, ignore and handle signals
	// TODO: Implement a working signal handler
	signal(SIGCHLD, SIG_IGN);
	signal(SIGHUP, SIG_IGN);

	// Fork off for the second time
	pid = fork();

	// Exit error if error, let parent terminate if success
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid > 0)
		exit(EXIT_SUCCESS);

	umask(0); // Set new file permissions
	chdir("/"); // Set directory at root directory

	// Close all open file descriptors
	int x;
	for (x = sysconf(_SC_OPEN_MAX); x>0; x--) {
		close (x);
	}

	openlog ("kinseywatch", LOG_PID, LOG_DAEMON); // Open the log file
}

