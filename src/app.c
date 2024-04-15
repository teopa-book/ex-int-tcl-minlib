#include <tcl.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    Tcl_FindExecutable(argv[0]);
    Tcl_Interp *interp = Tcl_CreateInterp();
    if (interp == NULL) {
        fprintf(stderr, "fail to create tcl interpreter\n");
        return EXIT_FAILURE;
    }

    int rv = Tcl_Init(interp);
    if (rv != TCL_OK) {
        fprintf(stderr, "fail to init tcl\n");
        Tcl_DeleteInterp(interp);
        return EXIT_FAILURE;
    }

    rv = Tcl_Eval(interp, "info library");
    const char *result = Tcl_GetStringResult(interp);
    if (rv != TCL_OK) {
        fprintf(stderr, "fail to evaluate file: %s\n", result);
        Tcl_DeleteInterp(interp);
        return EXIT_FAILURE;
    }

    printf("%s", result);
    Tcl_DeleteInterp(interp);
    return EXIT_SUCCESS;
}
