

#define RULES_OK 0
#define ERR_OUT_OF_MEMORY 1
#define ERR_UNEXPECTED_TYPE 2
#define ERR_IDENTIFIER_LENGTH 3  
#define ERR_UNEXPECTED_VALUE 4 
#define ERR_RULE_LIMIT_EXCEEDED 5 
#define ERR_PARSE_VALUE 101
#define ERR_PARSE_STRING 102
#define ERR_PARSE_NUMBER 103
#define ERR_PARSE_OBJECT 104
#define ERR_PARSE_ARRAY 105
#define ERR_EVENT_NOT_HANDLED 201
#define ERR_EVENT_MAX_CONFLICTS 202
#define ERR_MAX_STACK_SIZE 203
#define ERR_NO_ID_DEFINED 204
#define ERR_INVALID_ID 205
#define ERR_PARSE_PATH 206
#define ERR_MAX_NODE_RESULTS 207
#define ERR_MAX_RESULT_NODES 208
#define ERR_CONNECT_REDIS 301
#define ERR_REDIS_ERROR 302
#define ERR_NO_ACTION_AVAILABLE 303
#define ERR_NO_TIMERS_AVAILABLE 304
#define ERR_NEW_SESSION 305

#ifdef __cplusplus
extern "C" {
#endif

unsigned int createRuleset(void **handle, char *name, char *rules);
unsigned int deleteRuleset(void *handle);
unsigned int bindRuleset(void *handle, char *host, unsigned int port, char *password);
unsigned int assertEvent(void *handle, char *message);
unsigned int assertEvents(void *handle, char *messages, unsigned int *resultsLength, unsigned int **results);
unsigned int assertState(void *handle, char *state);
unsigned int startAction(void *handle, char **session, char **messages, void **actionHandle);
unsigned int completeAction(void *handle, void *actionHandle, char *session);
unsigned int abandonAction(void *handle, void *actionHandle);
unsigned int startTimer(void *handle, char *sid, unsigned int duration, char *timer);
unsigned int assertTimers(void *handle);
unsigned int getState(void *handle, char *sid, char **state);

#ifdef __cplusplus
}
#endif