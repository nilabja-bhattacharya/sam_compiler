#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#define debug(x) {/*printf(x);*/}
struct ASTNODE *getprogramnode(struct ASTNODE *statement_list, struct ASTNODE *function_list){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = PROGRAM_NODE;
    node->program_node.statement_list = statement_list;
    node->program_node.function_list = function_list;
    return node;
}

struct ASTNODE *getfunctionlistnode(struct ASTNODE *function_list, struct ASTNODE *function){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = FUNCTION_LIST_NODE;
    node->function_list_node.function_list = function_list;
    node->function_list_node.function = function;
    return node;
}

struct ASTNODE *getfunctionnode(struct ASTNODE *type, char *id, struct ASTNODE *argument_list, struct ASTNODE *scope){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = FUNCTION_NODE;
    node->function_node.type = type;
    node->function_node.id = id;
    node->function_node.argument_list = argument_list;
    node->function_node.scope = scope;
    return node;
}
struct ASTNODE *getargumentlistnode(struct ASTNODE *argument_list, struct ASTNODE *argument){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = ARGUMENT_LIST_NODE;
    node->argument_list_node.argument_list = argument_list;
    node->argument_list_node.argument = argument;
    return node;
}

struct ASTNODE *getargumentnode(struct ASTNODE *type, struct ASTNODE *iden){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = ARGUMENT_NODE;
    node->argument_node.type = type;
    node->argument_node.iden = iden;
    return node;
}

struct ASTNODE *getstatementlistnode(struct ASTNODE *statement_list, struct ASTNODE *statement){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_LIST_NODE;
    node->statement_list_node.statement_list = statement_list;
    node->statement_list_node.statement = statement;
    return node;
}

struct ASTNODE *getforblocknode(struct ASTNODE *declaration_list, struct ASTNODE *expr, struct ASTNODE *statement, struct ASTNODE *scope){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = FOR_BLOCK_NODE;
    node->for_block_node.declaration_list = declaration_list;
    node->for_block_node.expr = expr;
    node->for_block_node.statement = statement;
    node->for_block_node.scope = scope;
    return node;
}

struct ASTNODE *getwhileblocknode(struct ASTNODE *expr, struct ASTNODE *scope){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = WHILE_BLOCK_NODE;
    node->while_block_node.expr = expr;
    node->while_block_node.scope = scope;
    return node;
}

struct ASTNODE *getifblocknode(struct ASTNODE *expr, struct ASTNODE *if_scope, struct ASTNODE *else_scope, struct ASTNODE *if_block_scope){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = IF_BLOCK_NODE;
    node->if_block_node.expr =expr;
    node->if_block_node.if_scope = if_scope;
    node->if_block_node.else_scope = else_scope;
    node->if_block_node.if_block_scope = if_block_scope;
    return node;
}

struct ASTNODE *getdeclarationlistnode(int is_const, struct ASTNODE *type, struct ASTNODE *id_list){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = DECLARATION_LIST_NODE;
    node->declaration_list_node.is_const = is_const;
    node->declaration_list_node.type = type;
    node->declaration_list_node.id_list = id_list;
    return node;
}

struct ASTNODE *getidlistnode(struct ASTNODE *id_list, struct ASTNODE *iden, struct ASTNODE *expr){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = ID_LIST_NODE;
    node->id_list_node.id_list = id_list;
    node->id_list_node.iden = iden;
    node->id_list_node.expr = expr;
    return node;
}

struct ASTNODE *getidennode(char *id, struct ASTNODE *array, struct ASTNODE *argument_list){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = IDEN_NODE;
    node->iden_node.id = id;
    node->iden_node.array = array;
    node->iden_node.argument_list = argument_list;
    return node;
}

struct ASTNODE *getarraynode(struct ASTNODE *array, struct ASTNODE *expr){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = ARRAY_NODE;
    node->array_node.array = array;
    node->array_node.expr = expr;
    return node;
}

struct ASTNODE *getfunccallnode(char *id, struct ASTNODE *id_list){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = FUNC_CALL_NODE;
    node->func_call_node.id = id;
    node->func_call_node.id_list = id_list;
    return node;
}

struct ASTNODE *getassignmentopnode(struct ASTNODE *iden, struct ASTNODE *op, struct ASTNODE *expr){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = ASSIGNMENT_OP_NODE;
    node->assignment_op_node.iden = iden;
    node->assignment_op_node.op = op;
    node->assignment_op_node.expr = expr;
    return node;
}

struct ASTNODE *getincdecnode(struct ASTNODE *iden, UnaryOpType op, int preop){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = INC_DEC_NODE;
    node->inc_dec_node.iden = iden;
    node->inc_dec_node.op = op;
    node->inc_dec_node.preop = preop;
    return node;
}

struct ASTNODE *getintnode(int val){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = INT_NODE;
    node->int_node.val = val;
    //printf("%d", node->int_node.val);
    return node;
}

struct ASTNODE *getfloatnode(float val){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = FLOAT_NODE;
    node->float_node.val = val;
    return node;
}

struct ASTNODE *getcharnode(char *c){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = CHAR_NODE;
    node->char_node.val = c;
    return node;
}

struct ASTNODE *getstringnode(char *val){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STRING_NODE;
    node->string_node.val = val;
    return node;
}

struct ASTNODE *getnullnode(int val){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = NULL_NODE;
    node->null_node.val = val;
    return node;
}

struct ASTNODE *geteofnode(int val){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = EOF_NODE;
    node->eof_node.val = val;
    return node;
}

struct ASTNODE *getboolnode(int val){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = BOOL_NODE;
    node->bool_node.val = val;
    return node;
}

struct ASTNODE *getbinaryopnode(struct ASTNODE *expr1, BinaryOPType op, struct ASTNODE *expr2){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = BINARY_OP_NODE;
    node->binary_expr_node.expr1 = expr1;
    node->binary_expr_node.expr2 = expr2;
    node->binary_expr_node.op = op;
    return node;
}

struct ASTNODE *getternaryopnode(struct ASTNODE *expr1, struct ASTNODE *expr2, struct ASTNODE *expr3){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = TERNARY_OP_NODE;
    node->ternary_expr_node.expr1 = expr1;
    node->ternary_expr_node.expr2 = expr2;
    node->ternary_expr_node.expr3 = expr3;
    return node;
}

struct ASTNODE *getunaryopnode(UnaryOpType op, struct ASTNODE *expr){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = UNARY_OP_NODE;
    node->unary_expr_node.op = op;
    node->unary_expr_node.expr = expr;
    return node;
}

struct ASTNODE *getprintstmtnode(char *str, struct ASTNODE *id_list){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = PRINT_NODE;
    node->printstmt_node.str = str;
    node->printstmt_node.id_list = id_list;
    return node;
}

struct ASTNODE *getreturnnode(struct ASTNODE *expr){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = RETURN_NODE;
    node->return_node.expr = expr;
    return node;
}

struct ASTNODE *getopnode(Assign_Op op){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = OP_NODE;
    node->op_node.op = op;
    return node;
}

struct ASTNODE *gettypenode(TypeOp op){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = TYPE_NODE;
    node->op_node.op = op;
    return node;
}

struct ASTNODE *getscopenode(struct ASTNODE *statement_list){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = SCOPE_NODE;
    node->scope_node.statement_list = statement_list;
    return node;
}

struct ASTNODE *getstatementfornode(struct ASTNODE *forblk){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_NODE;
    node->statement_node.statementnodetype = FOR_BLOCK_NODE;
    node->statement_node.for_block = forblk;
    return node;
}
struct ASTNODE *getstatementwhilenode(struct ASTNODE *whlblk){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_NODE;
    node->statement_node.statementnodetype = WHILE_BLOCK_NODE;
    node->statement_node.while_block = whlblk;
    return node;
}
struct ASTNODE *getstatementifnode(struct ASTNODE *ifblk){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_NODE;
    node->statement_node.statementnodetype = IF_BLOCK_NODE;
    node->statement_node.if_block = ifblk;
    return node;
}
struct ASTNODE *getstatementdeclnode(struct ASTNODE *decllst){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_NODE;
    node->statement_node.statementnodetype = DECLARATION_LIST_NODE;
    node->statement_node.declaration_list = decllst;
    return node;
}
struct ASTNODE *getbrknode(){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_NODE;
    node->statement_node.statementnodetype = BREAK_NODE;
    return node;
}
struct ASTNODE *getcntnode(){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_NODE;
    node->statement_node.statementnodetype = CONTINUE_NODE;
    return node;
}
struct ASTNODE *getstatementprntnode(struct ASTNODE * prntst){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_NODE;
    node->statement_node.statementnodetype = PRINT_NODE;
    node->statement_node.print_stmt = prntst;
    return node;
}
struct ASTNODE *getstatementincdcnode(struct ASTNODE * incdc){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_NODE;
    node->statement_node.statementnodetype = INC_DEC_NODE;
    node->statement_node.incdc = incdc;
    return node;
}
struct ASTNODE *getstatementfnnode(struct ASTNODE *fn){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_NODE;
    node->statement_node.statementnodetype = FUNC_CALL_NODE;
    node->statement_node.fnc = fn;
    return node;
}

struct ASTNODE *getexpridnode(struct ASTNODE *id){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = EXPR_ID_NODE;
    node->expr_id_node.iden = id;
    return node;
}

struct ASTNODE *getstmtnode(UnaryOpType i){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = STATEMENT_NODE;
    node->statement_node.statementnodetype = SEMI_COLON_NODE;
    node->statement_node.op = i;
    return node;
}


struct ASTNODE *getexprfnnode(struct ASTNODE *fn){
    struct ASTNODE *node;
    node = (struct ASTNODE *) malloc(sizeof(struct ASTNODE));
    node->nodetype = EXPR_FN_NODE;
    node->expr_fn_node.func_call = fn;
    return node;
}




void printprefix(struct ASTNODE *root){
    //debug("hi");
    //printf("%d", root->nodetype);
    switch(root->nodetype){
        case PROGRAM_NODE:
            debug("PROGRAM_NODE\n");
            if(root->program_node.statement_list!=NULL)
                printprefix(root->program_node.statement_list);
            if(root->program_node.function_list!=NULL)
                printprefix(root->program_node.function_list);
            break;
        case FUNCTION_LIST_NODE:
            debug("FUNCTION_LIST_NODE\n");
            if(root->function_list_node.function_list!=NULL)
                printprefix(root->function_list_node.function_list);
            if(root->function_list_node.function!=NULL)
                printprefix(root->function_list_node.function);
            break;
        case FUNCTION_NODE:
            debug("FUNCTION_NODE\n");
            if(root->function_node.type!=NULL)
                printprefix(root->function_node.type);
            printf(" %s ", root->function_node.id);
            if(root->function_node.argument_list!=NULL)
                printprefix(root->function_node.argument_list);
            if(root->function_node.scope!=NULL)
                printprefix(root->function_node.scope);
            break;
        case ARGUMENT_LIST_NODE:
            debug("ARGUMENT_LIST_NODE");
            if(root->argument_list_node.argument_list!=NULL)
                printprefix(root->argument_list_node.argument_list);
            if(root->argument_list_node.argument!=NULL)
                printprefix(root->argument_list_node.argument);
            break;
        case ARGUMENT_NODE:
            debug("ARGUMENT_NODE");
            if(root->argument_node.type!=NULL)
                printprefix(root->argument_node.type);
            if(root->argument_node.iden!=NULL)
                printprefix(root->argument_node.iden);
            break;
        case STATEMENT_LIST_NODE:
            debug("STATEMENT_LIST_NODE");
            if(root->statement_list_node.statement_list!=NULL)
                printprefix(root->statement_list_node.statement_list);
            if(root->statement_list_node.statement!=NULL)
                printprefix(root->statement_list_node.statement);
            break;
        case STATEMENT_NODE:
            debug("STATEMENT_NODE");
            //getchar();
            switch (root->statement_node.statementnodetype)
            {
                case DECLARATION_LIST_NODE:
                    if(root->statement_node.declaration_list!=NULL)
                        printprefix(root->statement_node.declaration_list);
                    break;
                case FOR_BLOCK_NODE:
                    if(root->statement_node.for_block!=NULL)
                        printprefix(root->statement_node.for_block);
                    break;
                case WHILE_BLOCK_NODE:
                    if(root->statement_node.while_block!=NULL)
                        printprefix(root->statement_node.while_block);
                    break;
                case IF_BLOCK_NODE:
                    if(root->statement_node.if_block)
                        printprefix(root->statement_node.if_block);
                    break;
                case PRINT_NODE:
                    if(root->statement_node.print_stmt)
                        printprefix(root->statement_node.print_stmt);
                    break;
                case FUNC_CALL_NODE:
                    if(root->statement_node.print_stmt)
                        printprefix(root->statement_node.fnc);
                    break;
                case INC_DEC_NODE:
                    if(root->statement_node.incdc)
                        printprefix(root->statement_node.incdc);
                    break;
                case BREAK_NODE:
                    printf(" BREAK ");
                    break;
                case CONTINUE_NODE:
                    printf(" CONTINUE ");
                    break;
                case SEMI_COLON_NODE:
                    printf(" SEMI COLON ");
                    break;
            }
            break;
        case FOR_BLOCK_NODE:
            printf(" FOR ");
            if(root->for_block_node.declaration_list)
                printprefix(root->for_block_node.declaration_list);
            if(root->for_block_node.expr!=NULL)
                printprefix(root->for_block_node.expr);
            if(root->for_block_node.statement!=NULL)
                printprefix(root->for_block_node.statement);
            if(root->for_block_node.scope!=NULL)
                printprefix(root->for_block_node.scope);
            break;
        case WHILE_BLOCK_NODE:
            printf(" WHILE ");
            if(root->while_block_node.expr!=NULL)
                printprefix(root->while_block_node.expr);
            if(root->while_block_node.scope!=NULL)
                printprefix(root->while_block_node.scope);
            //printf("fni");
            //getchar();
            break;
        case IF_BLOCK_NODE:
            printf(" IF ");
            if(root->if_block_node.expr!=NULL)
                printprefix(root->if_block_node.expr);
            if(root->if_block_node.if_scope!=NULL){
                //getchar();
                printprefix(root->if_block_node.if_scope);
            }
            if(root->if_block_node.else_scope!=NULL)
                printprefix(root->if_block_node.else_scope);
            if(root->if_block_node.if_block_scope!=NULL)
                printprefix(root->if_block_node.if_block_scope);
            break;
        case DECLARATION_LIST_NODE:
            debug("DECLARATION_LIST_NODE");
            if(root->declaration_list_node.is_const==1)
                printf(" CONST ");
            if(root->declaration_list_node.type!=NULL)
                printprefix(root->declaration_list_node.type);
            if(root->declaration_list_node.id_list!=NULL)
                printprefix(root->declaration_list_node.id_list);
            break;
        case ID_LIST_NODE:
            debug("ID_LIST_NODE");
            if(root->id_list_node.expr!=NULL)
                printf(" = ");
            if(root->id_list_node.iden!=NULL)
            printprefix(root->id_list_node.iden);
            if(root->id_list_node.id_list!=NULL)
            printprefix(root->id_list_node.id_list);
            if(root->id_list_node.expr!=NULL)
            printprefix(root->id_list_node.expr);
            break;
        case IDEN_NODE:
            debug("IDEN_NODE");
            printf(" %s " , root->iden_node.id);
            //getchar();
            if(root->iden_node.array!=NULL)
            printprefix(root->iden_node.array);
            if(root->iden_node.argument_list!=NULL)
            printprefix(root->iden_node.argument_list);
            break;
        case ARRAY_NODE:
            if(root->array_node.array!=NULL)
            printprefix(root->array_node.array);
            if(root->array_node.expr!=NULL){
                printf(" [ ");
                printprefix(root->array_node.expr);
                printf(" ] ");
            }
            break;
        case FUNC_CALL_NODE:
            printf(" %s ", root->func_call_node.id);
            if(root->func_call_node.id_list!=NULL)
            printprefix(root->func_call_node.id_list);
            break;
        case SCOPE_NODE:
            //printf("SCOPE_NODE");
            //getchar();
            if(root->scope_node.statement_list!=NULL)
            printprefix(root->scope_node.statement_list);
            //printf("gi");
            //getchar();
            break;
        case TERNARY_OP_NODE:
            printf(" ? : ");
            if(root->ternary_expr_node.expr1!=NULL)
            printprefix(root->ternary_expr_node.expr1);
            if(root->ternary_expr_node.expr2!=NULL)
            printprefix(root->ternary_expr_node.expr2);
            if(root->ternary_expr_node.expr3!=NULL)
            printprefix(root->ternary_expr_node.expr3);
            break;
        case BINARY_OP_NODE:
            debug("BINARY_OP_NODE");
            switch(root->binary_expr_node.op){
                case ADD_N: printf(" + "); break;
                case SUB_N: printf(" - "); break;
                case MUL_N: printf(" * "); break;
                case DIV_N: printf(" / "); break;
                case MOD_N: printf(" %% "); break;
                case XOR_N: printf(" ^ "); break;
                case OR_N: printf(" || "); break;
                case AND_N: printf(" && "); break;
                case EQ_N: printf(" == "); break;
                case NEQ_N: printf(" != "); break;
                case LEQ_N: printf(" <= "); break;
                case GEQ_N: printf(" >= "); break;
                case LSS_N: printf(" < "); break;
                case GRT_N: printf(" > "); break;
            }
            if(root->binary_expr_node.expr1!=NULL)
            printprefix(root->binary_expr_node.expr1);
            if(root->binary_expr_node.expr2!=NULL)
            printprefix(root->binary_expr_node.expr2);
            break;
        case UNARY_OP_NODE:
            switch (root->unary_expr_node.op)
            {
                case NOT_N: printf(" ! "); break;
                case UMINUS_N: printf(" - "); break;
            }
            if(root->unary_expr_node.expr!=NULL)
            printprefix(root->unary_expr_node.expr);
            break;
        case ASSIGNMENT_OP_NODE:
            debug("ASSIGNMENT_OP_NODE");
            //getchar();
            if(root->assignment_op_node.op!=NULL)
            printprefix(root->assignment_op_node.op);
            if(root->assignment_op_node.iden!=NULL)
            printprefix(root->assignment_op_node.iden);
            if(root->assignment_op_node.expr!=NULL)
            printprefix(root->assignment_op_node.expr);
            break;
        case PRINT_NODE:
            printf(" printf ");
            printf(" %s ", root->printstmt_node.str);
            if(root->printstmt_node.id_list!=NULL)
            printprefix(root->printstmt_node.id_list);
            break;
        case INC_DEC_NODE:
            switch(root->inc_dec_node.op){
                case INC_N: printf(" ++ "); break;
                case DEC_N: printf(" -- "); break;
            }
            if(root->inc_dec_node.iden!=NULL)
            printprefix(root->inc_dec_node.iden);
            break;
        case RETURN_NODE:
            printf(" RETURN ");
            //getchar();
            if(root->return_node.expr)
            printprefix(root->return_node.expr);
            break;
        case INT_NODE:
            debug("INT_NODE");
            printf(" %d ",root->int_node.val);
            //getchar();
            break;
        case FLOAT_NODE:
            printf(" %f ", root->float_node.val);
            break;
        case BOOL_NODE:
            printf(" %d ", root->bool_node.val);
            break;
        case CHAR_NODE:
            printf(" %s ", root->char_node.val);
            break;
        case STRING_NODE:
            printf(" %s ", root->string_node.val);
            break;
        case EOF_NODE:
            if(root->eof_node.val==1)
                printf(" EOF ");
            break;
        case NULL_NODE:
            if(root->null_node.val==1)
                printf(" NULL ");
            break;
        case OP_NODE:
            debug("OP_NODE");
            //getchar();
            switch (root->op_node.op)
            {
                case EQU_N: printf(" = "); break;
                case PEQ_N: printf(" += "); break;
                case MEQ_N: printf(" -= "); break;
                case MULTEQ_N: printf(" *= "); break;
                case DIVEQ_N: printf(" /= "); break;
                case MODEQ_N: printf(" %%= "); break;
                default: break;
            }
            printf("%d", root->op_node.op);
            break;
        case TYPE_NODE:
            switch (root->type_node.op)
            {
                case INT_N: printf(" INT "); break;
                case FLOAT_N: printf(" FLOAT "); break;
                case CHAR_N: printf(" CHAR "); break;
                case BOOL_N: printf(" BOOL "); break;
                case FILE_T_N: printf(" FILE_T "); break;
                case VOID_N: printf(" VOID "); break;
            }
            break;
        case EXPR_ID_NODE:
            if(root->expr_id_node.iden)
                printprefix(root->expr_id_node.iden);
            break;
        case EXPR_FN_NODE:
            if(root->expr_fn_node.func_call)
                printprefix(root->expr_fn_node.func_call);
            break;
    }
    //printf("%d\n", root->nodetype);
    // //getchar();
}