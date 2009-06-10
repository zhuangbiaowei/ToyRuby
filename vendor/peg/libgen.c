#include "libgen.h"
#include <string.h>

char *basename (char *filename)
{
  char *p;

  if (filename == NULL || filename[0] == '\0')
    /* We return a pointer to a static string containing ".".  */
    p = (char *) ".";
  else
    {
      p = strrchr (filename, '\\');

      if (p == NULL)
	/* There is no slash in the filename.  Return the whole string.  */
	p = filename;
      else
	{
	  if (p[1] == '\0')
	    {
	      /* We must remove trailing '/'.  */
	      while (p > filename && p[-1] == '\\')
		--p;

	      /* Now we can be in two situations:
		 a) the string only contains '/' characters, so we return
		    '/'
		 b) p points past the last component, but we have to remove
		    the trailing slash.  */
	      if (p > filename)
		{
		  *p-- = '\0';
		  while (p > filename && p[-1] != '\\')
		    --p;
		}
	      else
		/* The last slash we already found is the right position
		   to return.  */
		while (p[1] != '\0')
		  ++p;
	    }
	  else
	    /* Go to the first character of the name.  */
	    ++p;
	}
    }
  p = strtok (p, ".");
  return p;
}