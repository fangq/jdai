#ifndef _JDATA_H_
#define _JDATA_H_

#include "cjson/cJSON.h"
#include "ubj/ubj.h"
s
#ifdef __cplusplus
extern "C"
{
#endif

enum TJDataType {jdText, jdBinary, jdNone};

typedef cJSON          tjdata;
typedef ubjw_context_t bjdata;

struct jdata{
    void        *root; /*the root of the document*/
    void        *node; /*current node*/
    TJDataType   type; /*is binary of text*/
};

int jd_load(jdata *jd, TJDataType type, char *filename);
int jd_save(jdata *jd, char *filename);
int jd_init(jdata *jd);
int jd_free(jdata *jd);
jdata * jd_getnode(jdata *jd, tjdata *path);
jdata * jd_gettype(jdata *jd, tjdata *path);
int jd_print(jdata *jd);


#ifdef __cplusplus
}
#endif

#endif