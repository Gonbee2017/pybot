prontera,0,0,0	script	再起動	-1,{
	end;
OnClock0359:
	announce "1分後にサーバーを再起動します。", 0;
	sleep 10000;
	announce "安全な場所へ移動してからログアウトしてください。", 0;
	sleep 20000;
	announce "停止まで残り30秒です。", 0;
	sleep 20000;
	announce "停止まで残り10秒です。", 0;
	sleep 10000;
	atcommand "@mapexit";
}
