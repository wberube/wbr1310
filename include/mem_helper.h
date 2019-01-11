/* vi: set sw=4 ts=4: */
/*
 * mem_helper.h
 *
 * The header file for memory helper module.
 */

#ifndef __MEM_HELPER_HEADER__
#define __MEM_HELPER_HEADER__

#ifdef CONFIG_MEM_HELPER_DISABLE

/* Use the stdc lib for memory allocation. */
#include <stdlib.h>
#include <string.h>

#define mh_dump(F)
#define mh_dump_used(F)
#define mh_diagnostic(F)
#define mh_init_all()
#define mh_free_all()
#define mh_free()

#define xmalloc(s)		malloc(s)
#define xstrdup(s)		strdup(s)
#define xcalloc(s)		calloc(s)
#define xfree(p)		free(p)
#define xrealloc(p, s)	realloc((p),(s))

#else	/* CONFIG_MEM_HELPER_DISABLE */

/* For debug */
#define CONFIG_MEM_HELPER_TRACKING			1
#define CONFIG_MEM_HELPER_TRACKING_FILES	512

/**************************************************************************/

/* diagnostic functions */
extern void mh_dump(FILE * fd);
extern void mh_dump_used(FILE * fd);
extern void mh_diagnostic(FILE * fd);

/* construction/destruction functions */
extern void mh_init_all(void);
extern void mh_free_all(void);
extern void mh_free(void * ptr);

#ifdef CONFIG_MEM_HELPER_TRACKING

extern void * mh_malloc(size_t size, const char * __file, int __line);
extern char * mh_strdup(const char * s, const char * __file, int __line);
extern void * mh_calloc(size_t nmemb, size_t size, const char * __file, int __line);
extern void * mh_realloc(void * ptr, size_t size, const char * __file, int __line);

#define xmalloc(s)		mh_malloc((s),__FILE__,__LINE__)
#define xstrdup(s)		mh_strdup((s),__FILE__,__LINE__)
#define xcalloc(n,s)	mh_calloc((n),(s),__FILE__,__LINE__)
#define xfree(p)		mh_free((p))
#define xrealloc(p,s)	mh_realloc((p),(s),__FILE__, __LINE__)

#else	/* #ifdef CONFIG_MEM_HELPER_TRACKING */

extern void * mh_malloc(size_t size);
extern char * mh_strdup(const char * s);
extern void * mh_calloc(size_t nmemb, size_t size);
extern void * mh_realloc(void * ptr, size_t size);

#define xmalloc(s)		mh_malloc((s))
#define xstrdup(s)		mh_strdup((s))
#define xcalloc(s)		mh_calloc((n),(s))
#define xfree(p)		mh_free((p))
#define xrealloc(p,s)	mh_realloc((p),(s))

#endif	/* end of #ifdef CONFIG_MEM_HELPER_TRACKING */
#endif	/* end of #ifdef CONFIG_MEM_HELPER_DISABLE */
#endif	/* end of #ifndef __MEM_HELPER_HEADER__ */
