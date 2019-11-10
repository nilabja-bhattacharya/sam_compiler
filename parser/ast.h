typedef enum  astnodetype {EXPR_FN_NODE, EXPR_ID_NODE, STATEMENT_NODE, PROGRAM_NODE, SCOPE_NODE, FUNCTION_LIST_NODE, FUNCTION_NODE, ARGUMENT_LIST_NODE, ARGUMENT_NODE, STATEMENT_LIST_NODE, FOR_BLOCK_NODE, ASSIGNMENT_OP_NODE, WHILE_BLOCK_NODE, IF_BLOCK_NODE, DECLARATION_LIST_NODE, ID_LIST_NODE, IDEN_NODE, ARRAY_NODE, RETURN_NODE, OP_NODE, PRINT_NODE, INC_DEC_NODE, FUNC_CALL_NODE, BINARY_OP_NODE, TERNARY_OP_NODE, UNARY_OP_NODE, TYPE_NODE, INT_NODE, FLOAT_NODE, CHAR_NODE, STRING_NODE, BOOL_NODE, NULL_NODE, EOF_NODE, SEMI_COLON_NODE, BREAK_NODE, CONTINUE_NODE} ASTNodeType;
typedef enum binaryoptype {ADD_N, SUB_N, MUL_N, DIV_N, XOR_N, OR_N, AND_N, EQ_N, NEQ_N, LEQ_N, LSS_N, GEQ_N, GRT_N, MOD_N } BinaryOPType;
typedef enum unaryoptye {NOT_N, UMINUS_N, INC_N, DEC_N, SEMI_COLON} UnaryOpType;
typedef enum assignmentop {EQU_N, PEQ_N, MEQ_N, MULTEQ_N, DIVEQ_N, MODEQ_N} Assign_Op;
typedef enum typeop {INT_N, FLOAT_N, CHAR_N, BOOL_N, FILE_T_N, VOID_N} TypeOp;
extern struct ASTNODE *getprogramnode(struct ASTNODE *statement_list, struct ASTNODE *function_list);
extern struct ASTNODE *getfunctionlistnode(struct ASTNODE *function_list, struct ASTNODE *function);
extern struct ASTNODE *getfunctionnode(struct ASTNODE *type, char *id, struct ASTNODE *argument_list, struct ASTNODE *scope);
extern struct ASTNODE *getargumentlistnode(struct ASTNODE *argument_list, struct ASTNODE *argument);
extern struct ASTNODE *getargumentnode(struct ASTNODE *type, struct ASTNODE *iden);
extern struct ASTNODE *getstatementlistnode(struct ASTNODE *statement_list, struct ASTNODE *statement);
extern struct ASTNODE *getforblocknode(struct ASTNODE *declaration_list, struct ASTNODE *expr, struct ASTNODE *statement, struct ASTNODE *scope);
extern struct ASTNODE *getwhileblocknode(struct ASTNODE *expr, struct ASTNODE *scope);
extern struct ASTNODE *getifblocknode(struct ASTNODE *expr, struct ASTNODE *if_scope, struct ASTNODE *else_scope, struct ASTNODE *if_block_scope);
extern struct ASTNODE *getdeclarationlistnode(int is_const, struct ASTNODE *type, struct ASTNODE *id_list);
extern struct ASTNODE *getidlistnode(struct ASTNODE *id_list, struct ASTNODE *iden, struct ASTNODE *expr);
extern struct ASTNODE *getidennode(char *id, struct ASTNODE *array, struct ASTNODE *argument_list);
extern struct ASTNODE *getarraynode(struct ASTNODE *array, struct ASTNODE *expr);
extern struct ASTNODE *getfunccallnode(char *id, struct ASTNODE *id_list);
extern struct ASTNODE *getassignmentopnode(struct ASTNODE *iden, struct ASTNODE *op, struct ASTNODE *expr);
extern struct ASTNODE *getincdecnode(struct ASTNODE *iden, UnaryOpType op, int preop);
extern struct ASTNODE *getintnode(int val);
extern struct ASTNODE *getfloatnode(float val);
extern struct ASTNODE *getcharnode(char *c);
extern struct ASTNODE *getstringnode(char *val);
extern struct ASTNODE *getnullnode(int val);
extern struct ASTNODE *geteofnode(int val);
extern struct ASTNODE *getboolnode(int val);
extern struct ASTNODE *getbinaryopnode(struct ASTNODE *expr1, BinaryOPType op, struct ASTNODE *expr2);
extern struct ASTNODE *getternaryopnode(struct ASTNODE *expr1, struct ASTNODE *expr2, struct ASTNODE *expr3);
extern struct ASTNODE *getunaryopnode(UnaryOpType op, struct ASTNODE *expr);
extern struct ASTNODE *getprintstmtnode(char *str, struct ASTNODE *id_list);
extern struct ASTNODE *getreturnnode(struct ASTNODE *expr);
extern struct ASTNODE *gettypenode(TypeOp );
extern struct ASTNODE *getscopenode(struct ASTNODE *);
extern struct ASTNODE *getopnode(Assign_Op op);
extern void printprefix(struct ASTNODE *root);
extern struct ASTNODE *getstatementfornode(struct ASTNODE *);
extern struct ASTNODE *getstatementwhilenode(struct ASTNODE *);
extern struct ASTNODE *getstatementifnode(struct ASTNODE *);
extern struct ASTNODE *getstatementdeclnode(struct ASTNODE *);
extern struct ASTNODE *getbrknode();
extern struct ASTNODE *getcntnode();
extern struct ASTNODE *getstatementprntnode(struct ASTNODE *);
extern struct ASTNODE *getstatementincdcnode(struct ASTNODE *);
extern struct ASTNODE *getstatementfnnode(struct ASTNODE *);
extern struct ASTNODE *getexpridnode(struct ASTNODE *);
extern struct ASTNODE *getexprfnnode(struct ASTNODE *);
extern struct ASTNODE *getstmtnode(UnaryOpType);
extern struct ASTNODE *ast;
struct ASTNODE{
    ASTNodeType nodetype;
    union{
        struct start{
            struct ASTNODE *program;
        }start_node;
        struct program{
            struct ASTNODE *statement_list;
            struct ASTNODE *function_list;
        }program_node;
        struct function_list{
            struct ASTNODE *function_list;
            struct ASTNODE *function;
        }function_list_node;
        struct function{
            struct ASTNODE *type;
            char *id;
            struct ASTNODE *argument_list;
            struct ASTNODE *scope;
        }function_node;
        struct argument_list{
            struct ASTNODE *argument_list;
            struct ASTNODE *argument;
        }argument_list_node;
        struct argument{
            struct ASTNODE *type;
            struct ASTNODE *iden;
        }argument_node;
        struct statement_list{
            struct ASTNODE *statement_list;
            struct ASTNODE *statement;
        }statement_list_node;
        struct for_block{
            struct ASTNODE *declaration_list;
            struct ASTNODE *expr;
            struct ASTNODE *statement;
            struct ASTNODE *scope;
        }for_block_node;
        struct while_block{
            struct ASTNODE *expr;
            struct ASTNODE *scope;
        }while_block_node;
        struct if_block{
            struct ASTNODE *expr;
            struct ASTNODE *if_scope;
            struct ASTNODE *else_scope;
            struct ASTNODE *if_block_scope;
        }if_block_node;
        struct declaration_list{
            int is_const;
            struct ASTNODE *type;
            struct ASTNODE *id_list;
        }declaration_list_node;
        struct id_list{
            struct ASTNODE *iden;
            struct ASTNODE *id_list;
            struct ASTNODE *expr;
        }id_list_node;
        struct iden{
            char *id;
            struct ASTNODE *array;
            struct ASTNODE *argument_list;
        }iden_node;
        struct array{
            struct ASTNODE *array;
            struct ASTNODE *expr;
        }array_node;
        struct func_call{
            char *id;
            struct ASTNODE *id_list;
        }func_call_node;
        struct scope{
            struct ASTNODE *statement_list;
        }scope_node;
        struct ternary_expr{
            struct ASTNODE *expr1;
            struct ASTNODE *expr2;
            struct ASTNODE *expr3;
        }ternary_expr_node;
        struct binary_expr{
            BinaryOPType op;
            struct ASTNODE *expr1;
            struct ASTNODE *expr2;
        }binary_expr_node;
        struct unary_expr{
            UnaryOpType op;
            struct ASTNODE *expr;
        }unary_expr_node;
        struct assignment_op{
            struct ASTNODE *iden;
            struct ASTNODE *op;
            struct ASTNODE *expr;
        }assignment_op_node;
        struct printstmt{
            char *str;
            struct ASTNODE *id_list;
        }printstmt_node;
        struct inc_dec{
            UnaryOpType op;
            struct ASTNODE *iden;
            int preop;
        }inc_dec_node;
        struct return_expr{
            struct ASTNODE *expr;
        }return_node;
        struct intnode{
            int val;
        }int_node;
        struct floatnode{
            float val;
        }float_node;
        struct charnode{
            char *val;
        }char_node;
        struct stringnode{
            char *val;
        }string_node;
        struct boolnode{
            int val;
        }bool_node;
        struct nullnode{
            int val;
        }null_node;
        struct eofnode{
            int val;
        }eof_node;
        struct opnode{
            Assign_Op op;
        }op_node;
        struct typenode{
            TypeOp op;
        }type_node;
        struct statementnode{
            ASTNodeType statementnodetype;
            union{
                struct ASTNODE *for_block;
                struct ASTNODE *while_block;
                struct ASTNODE *if_block;
                struct ASTNODE *declaration_list;
                struct ASTNODE *print_stmt;
                struct ASTNODE *incdc;
                struct ASTNODE *fnc;
                UnaryOpType op;
            };
        }statement_node;
        struct expridnode{
            struct ASTNODE *iden;
        }expr_id_node;
        struct exprfnnode{
            struct ASTNODE *func_call;
        }expr_fn_node;
    };
};

