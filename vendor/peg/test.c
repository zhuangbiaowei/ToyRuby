typedef union Node Node;

struct Rule	 { int type;  Node *next;   char *name;	 Node *variables;  Node *expression;  int id;  int flags;	};
struct Variable	 { int type;  Node *next;   char *name;  Node *value;  int offset;					};
struct Name	 { int type;  Node *next;   Node *rule;  Node *variable;						};
struct Dot	 { int type;  Node *next;										};
struct Character { int type;  Node *next;   char *value;								};
struct String	 { int type;  Node *next;   char *value;								};
struct Class	 { int type;  Node *next;   unsigned char *value;							};
struct Action	 { int type;  Node *next;   char *text;	  Node *list;  char *name;  Node *rule;				};
struct Predicate { int type;  Node *next;   char *text;									};
struct Alternate { int type;  Node *next;   Node *first;  Node *last;							};
struct Sequence	 { int type;  Node *next;   Node *first;  Node *last;							};
struct PeekFor	 { int type;  Node *next;   Node *element;								};
struct PeekNot	 { int type;  Node *next;   Node *element;								};
struct Query	 { int type;  Node *next;   Node *element;								};
struct Star	 { int type;  Node *next;   Node *element;								};
struct Plus	 { int type;  Node *next;   Node *element;								};
struct Any	 { int type;  Node *next;										};

union Node
{
  int			type;
  struct Rule		rule;
  struct Variable	variable;
  struct Name		name;
  struct Dot		dot;
  struct Character	character;
  struct String		string;
  struct Class		cclass;
  struct Action		action;
  struct Predicate	predicate;
  struct Alternate	alternate;
  struct Sequence	sequence;
  struct PeekFor	peekFor;
  struct PeekNot	peekNot;
  struct Query		query;
  struct Star		star;
  struct Plus		plus;
  struct Any		any;
};

Node *name;

static void yy_2_primary(char *yytext, int yyleng)
{
  printf("do yy_2_primary\n");
  name=makeName(findRule(yytext));
  name->name.variable= pop();
  push(name);
}