extern char *get_tpidr();

static inline struct pthread *__pthread_self()
{
	char *self=get_tpidr();
	return (void*)(self + 16 - sizeof(struct pthread));
}

#define TLS_ABOVE_TP
#define TP_ADJ(p) ((char *)(p) + sizeof(struct pthread) - 16)

#define MC_PC pc
