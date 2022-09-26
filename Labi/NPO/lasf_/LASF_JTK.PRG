* † -> Š‘

set safe off
*set console on
set console off
clear

close data

************


sele 1
*use  rj_
use  lasf_j

sele 2
*use  ks_
use  lasf_k
zap


sele lasf_j
goto top

LOCATE  for .T.

**

do while .T.

  if eof()
	exit
  endif

do recxx

sele lasf_j
skip

enddo

**

close data
***********

clear


return
**************************************************
**************************************************
proc recxx

sele lasf_j
scat memvar 

sele lasf_k

**

append blank

repl lasf_kdata   with m.lasf_jdata
repl lasf_kdokk   with m.lasf_jdokk
repl lasf_kdokn   with m.lasf_jdokn
repl lasf_kdokd   with m.lasf_jdokd
repl lasf_kto    with m.lasf_jto

repl lasf_ks     with m.lasf_jdb
repl lasf_ksn    with m.lasf_jdbn
repl lasf_kks    with m.lasf_jkr
repl lasf_kksn   with m.lasf_jkrn

repl lasf_kdb   with m.lasf_jrub
repl lasf_kkr   with 0

******
append blank

repl lasf_kdata   with m.lasf_jdata
repl lasf_kdokk   with m.lasf_jdokk
repl lasf_kdokn   with m.lasf_jdokn
repl lasf_kdokd   with m.lasf_jdokd
repl lasf_kto     with m.lasf_jto


repl lasf_ks     with m.lasf_jkr
repl lasf_ksn    with m.lasf_jkrn
repl lasf_kks    with m.lasf_jdb
repl lasf_kksn   with m.lasf_jdbn

repl lasf_kkr   with m.lasf_jrub

repl lasf_kdb   with 0


return
***************************
***************************
