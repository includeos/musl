extern char *get_tpidr();

static inline struct pthread *__pthread_self()
{
	char *self=get_tpidr();
	return (void*)(self - sizeof(struct pthread));
}

#define TLS_ABOVE_TP
#define GAP_ABOVE_TP 16
#define TP_ADJ(p) ((char *)(p) + sizeof(struct pthread))

#define MC_PC pc
