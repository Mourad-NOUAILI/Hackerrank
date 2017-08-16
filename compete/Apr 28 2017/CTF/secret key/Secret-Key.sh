#!/bin/bash

#https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/secret/key.json
#https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/secret/secret_json/"$k.json"
welcome() {
  echo '

   ÛÛÛÛÛ                         ÛÛÛÛÛ                                                        ÛÛÛÛÛ
  °°ÛÛÛ                         °°ÛÛÛ                                                        °°ÛÛÛ
  °ÛÛÛÛÛÛÛ    ÛÛÛÛÛÛ    ÛÛÛÛÛÛ  °ÛÛÛ ÛÛÛÛÛ  ÛÛÛÛÛÛ  ÛÛÛÛÛÛÛÛ  ÛÛÛÛÛÛÛÛ   ÛÛÛÛÛÛ   ÛÛÛÛÛÛÛÛ   °ÛÛÛ ÛÛÛÛÛ
  °ÛÛÛ°°ÛÛÛ  °°°°°ÛÛÛ  ÛÛÛ°°ÛÛÛ °ÛÛÛ°°ÛÛÛ  ÛÛÛ°°ÛÛÛ°°ÛÛÛ°°ÛÛÛ°°ÛÛÛ°°ÛÛÛ °°°°°ÛÛÛ °°ÛÛÛ°°ÛÛÛ  °ÛÛÛ°°ÛÛÛ
  °ÛÛÛ °ÛÛÛ   ÛÛÛÛÛÛÛ °ÛÛÛ °°°  °ÛÛÛÛÛÛ°  °ÛÛÛÛÛÛÛ  °ÛÛÛ °°°  °ÛÛÛ °°°   ÛÛÛÛÛÛÛ  °ÛÛÛ °ÛÛÛ  °ÛÛÛÛÛÛ°
  °ÛÛÛ °ÛÛÛ  ÛÛÛ°°ÛÛÛ °ÛÛÛ  ÛÛÛ °ÛÛÛ°°ÛÛÛ °ÛÛÛ°°°   °ÛÛÛ      °ÛÛÛ      ÛÛÛ°°ÛÛÛ  °ÛÛÛ °ÛÛÛ  °ÛÛÛ°°ÛÛÛ
  ÛÛÛÛ ÛÛÛÛÛ°°ÛÛÛÛÛÛÛÛ°°ÛÛÛÛÛÛ  ÛÛÛÛ ÛÛÛÛÛ°°ÛÛÛÛÛÛ  ÛÛÛÛÛ     ÛÛÛÛÛ    °°ÛÛÛÛÛÛÛÛ ÛÛÛÛ ÛÛÛÛÛ ÛÛÛÛ ÛÛÛÛÛ
  °°°° °°°°°  °°°°°°°°  °°°°°°  °°°° °°°°°  °°°°°°  °°°°°     °°°°°      °°°°°°°° °°°° °°°°° °°°° °°°°°
  '
  echo -ne "\t\tContest CTF: https://www.hackerrank.com/capture-the-flag\n"
  echo -ne "\t\tChallenge: Secret Key\n"
  echo

}

go() {
  values=()
  echo "*****************************************"
  echo "***Hackerrank contest challenges*********"
  echo "***capture-the-flag: secret-key**********"
  echo "*****************************************"
  echo
  echo
  echo -ne "[+]Getting secret news from https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/secret/key.json... be patient...\n\n"
  json=$(curl -s https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/secret/key.json | jq 'keys[]')
  i=0
  while IFS=' ' read -ra key; do
    k=`echo "$key" | sed -e 's/^"//' -e 's/"$//'`
    value=$(curl -s "https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/secret/secret_json/$k.json" | jq -r '.news_title')
    values[$i]=$value
    i=$(($i+1))
  done <<< "$json"

  echo -ne "[+]Display ${#values[@]} sorted secret news\n\n"
  printf '%s\n' "${values[@]}" | LC_COLLATE=C sort
}

#Main
welcome
go
