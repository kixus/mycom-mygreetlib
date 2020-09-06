(import build/mycom_mygreetlib :as grt)


(print "INFO:  test:  Running tests...")

(printf "INFO:  test:  hello(): %q" (grt/hello "World"))

(printf "INFO:  test:  namaste(): %q" (grt/namaste "World"))
