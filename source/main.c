#include <stdio.h>

#include <janet.h>


#include <stdlib.h>
#include <sys/stat.h>

const char * file_name_cs = "main.c";

static Janet mycom_mygreelib_hello(int32_t argc, Janet *argv) {
    const char * method_name_cs = "mycom_mygreelib_hello";
    janet_fixarity(argc, 1);
    const uint8_t * target_cs = janet_unwrap_string(argv[0]);
    char greet_cs[1000];
    sprintf(greet_cs, "%s %s!", "Hello ", target_cs);
    Janet ret_jstr = janet_wrap_string(janet_cstring(greet_cs));
    return ret_jstr;
}

static Janet mycom_mygreelib_namaste(int32_t argc, Janet *argv) {
    const char * method_name_cs = "mycom_mygreelib_namaste";
    janet_fixarity(argc, 1);
    const uint8_t * target_cs = janet_unwrap_string(argv[0]);
    char greet_cs[1000];
    sprintf(greet_cs, "%s %s!", "Namaste ", target_cs);
    Janet ret_jstr = janet_wrap_string(janet_cstring(greet_cs));
    return ret_jstr;
}


/*****************************************************************************/

static const JanetReg cfuns[] = {
    {   "hello",
        mycom_mygreelib_hello,
        "(mycom_mygreelib/hello <arg>)\n\n"
        "Says 'Hello <arg>!'"
    },
    {   "namaste",
        mycom_mygreelib_namaste,
        "(mycom_mygreelib/namaste <arg>)\n\n"
        "Says 'Namaste <arg>!'"
    },
    {NULL, NULL, NULL}  // DO NOT COMMENT THIS OUT 
};

JANET_MODULE_ENTRY(JanetTable *env) {
    janet_cfuns(env, "mycom_mygreetlib", cfuns);
}

