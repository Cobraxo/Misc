
#ifndef AUTO
#define AUTO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

static char *c =
"\
#include <stdio.h>\n\
#include <stdlib.h>\n\
\n\
\n\
int main(void) {\n\
\n\
\n\
    return 0;\n\
\n\
}\n\
";

static char *cc =
"\
#include <iostream>\n\
\n\
using namespace std;\n\
\n\
\n\
int main(void) {\n\
\n\
\n\
    return 0;\n\
\n\
}\n\
";

static char *html =
"\
<!DOCTYPE html>\n\
<html lang=\"en\">\n\
<head>\n\
    <meta charset=\"UTF-8\">\n\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n\
    <meta http-equiv=\"X-UA-Compatible\" content=\"ie=edge\">\n\
    <title>Document</title>\n\
</head>\n\
<body>\n\
    \n\
</body>\n\
</html>\n\
";

#endif
