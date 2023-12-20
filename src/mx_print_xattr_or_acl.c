#include "uls.h"

void mx_print_xattr_or_acl(char *path) {
    ssize_t xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
    acl_t acl = acl_get_file(path, ACL_TYPE_EXTENDED);

    if (xattr > 0) {
        mx_printchar('@');
    }
    else if (acl != NULL) {
        mx_printchar('+');
        acl_free(acl);
    }
    else {
        mx_printchar(' ');
    }
}
