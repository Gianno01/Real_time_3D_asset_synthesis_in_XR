#!/usr/bin/env bash
# set_ip.sh — trova l'IP di questo PC e lo sostituisce al posto del vecchio nei file del progetto.
#
# Uso (dalla cartella del progetto, anche con Git Bash su Windows):
#   bash set_ip.sh                    mostra cosa cambierebbe (prova a vuoto)
#   bash set_ip.sh --apply            applica le modifiche (copia di sicurezza *.bak_ip accanto ai file)
#   bash set_ip.sh --apply --ip 192.168.1.20      usa questo IP invece di quello rilevato
#   bash set_ip.sh --apply --old 10.0.0.5         aggiungi un vecchio IP da sostituire (ripetibile)
set -u

APPLY=0; NEW_IP=""; OLD_IPS=("10.54.15.50" "169.254.48.171" "192.168.50.133")
while [ $# -gt 0 ]; do
  case "$1" in
    --apply) APPLY=1 ;;
    --ip)    NEW_IP="${2:-}"; shift ;;
    --old)   OLD_IPS+=("${2:-}"); shift ;;
    -h|--help) sed -n '2,10p' "$0"; exit 0 ;;
    *) echo "Opzione sconosciuta: $1"; exit 1 ;;
  esac
  shift
done

valid() { [[ "$1" =~ ^([0-9]{1,3}\.){3}[0-9]{1,3}$ ]]; }
# scarta link-local, loopback e reti virtuali di Docker/WSL/VPN
bad()   { [[ "$1" =~ ^(169\.254\.|127\.|172\.1[6-9]\.|172\.2[0-9]\.|172\.3[0-1]\.) ]]; }

detect_ip() {
  local cand=() ip
  if command -v ipconfig >/dev/null 2>&1 && ipconfig 2>/dev/null | grep -qi "IPv4"; then       # Windows
    while IFS= read -r ip; do cand+=("$ip"); done < <(ipconfig 2>/dev/null | tr -d '\r' | grep -i "IPv4" | sed 's/.*: *//')
  elif command -v ipconfig >/dev/null 2>&1 && command -v ifconfig >/dev/null 2>&1; then          # macOS
    for i in en0 en1 en2; do ip="$(ipconfig getifaddr "$i" 2>/dev/null)"; [ -n "$ip" ] && cand+=("$ip"); done
  elif command -v hostname >/dev/null 2>&1 && hostname -I >/dev/null 2>&1; then                  # Linux
    for ip in $(hostname -I); do cand+=("$ip"); done
  fi
  for ip in "${cand[@]}"; do
    valid "$ip" && ! bad "$ip" && { echo "$ip"; return; }
  done
}

[ -z "$NEW_IP" ] && NEW_IP="$(detect_ip)"
if [ -z "$NEW_IP" ] || ! valid "$NEW_IP"; then
  echo "Non riesco a rilevare l'IP. Indicalo a mano:  bash set_ip.sh --apply --ip 192.168.x.x"; exit 1
fi
echo "IP di questo PC: $NEW_IP"

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SELF="$ROOT/$(basename "${BASH_SOURCE[0]}")"
EXT='json|cs|unity|prefab|asset|txt|md|yml|yaml|conf|js|html|ps1|sh|env'
EXCL='/(\.git|Library|Temp|obj|Logs|node_modules|builds?|\.vs|\.vscode|UserSettings|\.utmp)/'
total=0
for old in "${OLD_IPS[@]}"; do
  valid "$old" || continue
  [ "$old" = "$NEW_IP" ] && continue
  esc="${old//./\\.}"
  while IFS= read -r f; do
    [[ "$f" =~ $EXCL ]] && continue
    [[ "$f" =~ \.($EXT)$ ]] || continue
    [[ "$f" =~ \.bak_ip$ ]] && continue
    [ "$f" = "$SELF" ] && continue
    n="$(grep -c "$esc" "$f" 2>/dev/null)"
    echo "  $n× $old → $NEW_IP   ${f#$ROOT/}"
    total=$((total+n))
    if [ "$APPLY" = 1 ]; then
      cp -p "$f" "$f.bak_ip" && sed -i.tmp_ip "s/$esc/$NEW_IP/g" "$f" && rm -f "$f.tmp_ip"
    fi
  done < <(grep -rIl --exclude-dir=.git --exclude-dir=Library --exclude-dir=Temp --exclude-dir=obj --exclude-dir=Logs --exclude-dir=node_modules -e "$esc" "$ROOT" 2>/dev/null)
done

# IP.txt: sempre aggiornato con l'IP attuale
find "$ROOT" -maxdepth 3 -name IP.txt -not -path '*/.git/*' 2>/dev/null | while IFS= read -r f; do
  echo "  IP.txt → $NEW_IP   ${f#$ROOT/}"
  [ "$APPLY" = 1 ] && printf '%s' "$NEW_IP" > "$f"
done

echo
if [ "$APPLY" = 1 ]; then
  echo "Fatto: $total sostituzioni. Reimporta in n8n i workflow modificati e rimetti l'IP nelle Impostazioni del visore."
  echo "Le copie di sicurezza sono *.bak_ip (cancellale quando hai verificato)."
else
  echo "Prova a vuoto: $total sostituzioni previste. Per applicarle:  bash set_ip.sh --apply"
fi
