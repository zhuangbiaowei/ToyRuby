#include "libgen.h"
#include <string.h>

char *basename (char *filename){
	char *p,*q;
	int s=0,e=0;
	int f_len=strlen(filename);
	char *r=malloc(f_len);

	if (filename == NULL || filename[0] == '\0'){    
		return ".";
	}else{
		p = strrchr(filename,'\\');
		q = strrchr(filename,'.');
		if (p == NULL){
			s=0;
		} else {
			s=f_len-strlen(++p);
		}
		if (q == NULL){
			e=f_len;
		} else {
			e=f_len-strlen(q);
		}
		if (p == NULL){
			strncpy(r,filename,e-s);
		}else{
			strncpy(r,p,e-s);
		}
		r[e-s]='\0';
		return r;
	}
}

char *dirname (char *filename){
	char *p;
	int e=0;
	int f_len=strlen(filename);
	char *r=malloc(f_len);

	if (filename == NULL || filename[0] == '\0'){    
		return ".";
	}else{
		p = strrchr(filename,'\\');		
		if (p == NULL){
			return ".";
		} else {
			e=f_len-strlen(++p);
			strncpy(r,filename,e);
			r[e]='\0';
			return r;
		}
	}
}