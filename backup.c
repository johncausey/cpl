//
// Program to backup personal data over ssh.
//

#include <libssh/libssh.h> // ssh
#include <stdlib.h>
#include <stdio.h>
#include <syslog.h> // syslog


int main( int argc, char ** argv ) {

	// Open syslog and notify of start
	openlog("KinseyWatch", LOG_PID, LOG_DAEMON);
	syslog(LOG_NOTICE, "KinseyWatch has started.");

	printf("Connecting...\n");

	const char * user_for_ssh = "user";
	const char * ip_for_ssh = "ip";
	int port = 22;
	int rc;

	ssh_session kinsey_ssh_session = ssh_new();
	if (kinsey_ssh_session == NULL) {
		exit(-1);
	}

	ssh_options_set(kinsey_ssh_session, SSH_OPTIONS_HOST, &ip_for_ssh);
	ssh_options_set(kinsey_ssh_session, SSH_OPTIONS_USER, &user_for_ssh);
	ssh_options_set(kinsey_ssh_session, SSH_OPTIONS_PORT, &port);

	rc = ssh_connect(kinsey_ssh_session);
	if (rc != SSH_OK) {
		fprintf(stderr, "Error connecting to server: %s\n", ssh_get_error(kinsey_ssh_session));
		exit(-1);
	}

	ssh_free(kinsey_ssh_session);
	syslog(LOG_NOTICE, "KinseyWatch has finished.");
	closelog();
	return 0;
}
