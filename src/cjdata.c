#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cjdata.h"

int jd_load(char *filename, TJDataType type, jdata *jd){
    FILE *fp;
    jd_free(jd);
    if((fp=fopen(filename))==NULL){
        return -1;
    }
    if(type==jdBinary)
        jd->data=ubjw_open_file(fp);
    else{
        jd->data=cJSON_Parse(buf);
    }
    jd->type=type;
    jd->node=jd->data;
    return 0;
}
int jd_save(char *filename, jdata *jd){

}
int jd_init(jdata *jd){
    jd->data=NULL;
    jd->node=NULL;
    jd->type=jdNone;
}
int jd_free(jdata *jd){
    if(jd->type==jdBinary)
        ubjr_close_context((bdata*)(jd->data));
    else if(jd->type==jdText)
        cJSON_Delete((tdata*)(jd->data));
    jd->data=NULL;
    jd->node=NULL;
    jd->type=jdNone;
}
jdata * jd_getnode(jdata *jd, tjdata *path){

}
jdata * jd_gettype(jdata *jd, tjdata *path){

}
int jd_print(jdata *jd){

}