(declare-project
    :name                   "mycom-mygreetlib"
    :author                 "Rajesh Krishnan"
    :email                  "raj.janet@dev.kix.us" 
    :license                "GNU LGPL"
    :url                    "https://github.com/kixus/mycom-mygreetlib"
    :repo                   "git@github.com:kixus/mycom-mygreetlib.git"
)



(declare-native
    :name                   "mycom_mygreetlib"
#   commenting out :entry-name as Janet core fails to load a voided _janet_entry entrypoint.
#    :entry-name             "janet_module_entry_mycom_mygreetlib"
    :cflags                 (unless (= :windows (os/which)) [ "-pthread" ]) 
    :source                 @["source/main.c" ]
)

