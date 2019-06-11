//= Auriga Script ==============================================================
// Ragnarok Online Hero Vestige Script	by refis
//==============================================================================

//============================================================
// NPC
//------------------------------------------------------------
mid_camp,207,290,5	script	次元の狭間の案内員#gk01	852,{
	mes "[遠征隊員フィル]";
	mes "次元の狭間内部に行きたいのですか？";
	mes "それなら、そこにある次元移動機を";
	mes "使ってください。";
	next;
	if(select("次元の狭間について聞く","会話を終わらせる") == 2) {
		mes "‐あなたはその場から離れた‐";
		close;
	}
	mes "[遠征隊員フィル]";
	mes "少し前から、私たちは次元の狭間を";
	mes "利用して、こことミッドガルドを";
	mes "行き来しているじゃありませんか？";
	mes "こちらの狭間も、そういった";
	mes "通路のようなものだと";
	mes "考えていただければいいと思います。";
	next;
	mes "[遠征隊員フィル]";
	mes "次元の狭間の中を通ることで";
	mes "いろいろな場所に移動する方法が";
	mes "発見されたんです。";
	next;
	mes "[遠征隊員フィル]";
	mes "それで、安定性の確認がとれた通路が";
	mes "公開されたのです。";
	mes "これで、ビフロストとモロク、";
	mes "エルディカスティスへの";
	mes "移動が楽になりました。";
	next;
	mes "[遠征隊員フィル]";
	mes "次元の狭間は時間と空間が";
	mes "歪んだ場所です。";
	mes "もし道に迷ってしまったら";
	mes "どこに放り出されるかわかりません。";
	mes "調査済みの地域のみ利用してください。";
	next;
	mes "[遠征隊員フィル]";
	mes "中で迷子になると救出は困難ですので";
	mes "くれぐれも気を付けてください。";
	close;
}

mid_camp,212,290,3	script	次元の狭間の案内員#gk02	852,{
	mes "[遠征隊員]";
	mes "次元の狭間内部に行きたい方は";
	mes "次元移動機を利用してください。";
	mes "次元の狭間内部は";
	mes "まだ探索中の通路もありますので";
	mes "道に迷わない様に気を付けて下さい。";
	close;
}

moc_fild22b,225,198,5	script	次元の狭間の案内員#gk03	707,{
	mes "[遠征隊員]";
	mes "次元の狭間内部に行きたいのですか？";
	mes "それなら、そこにある次元移動機を";
	mes "使ってください。";
	next;
	if(select("次元の狭間について聞く","会話終了") == 2) {
		mes "‐あなたはその場から離れた‐";
		close;
	}
	mes "[遠征隊員]";
	mes "少し前から、私たちは次元の狭間を";
	mes "利用して、こことミッドガルドを";
	mes "行き来しているじゃありませんか？";
	mes "こちらの狭間も、そういった";
	mes "通路のようなものだと";
	mes "考えていただければいいと思います。";
	next;
	mes "[遠征隊員]";
	mes "次元の狭間の中を通ることで";
	mes "いろいろな場所に移動する方法が";
	mes "発見されたんです。";
	next;
	mes "[遠征隊員]";
	mes "それで、安定性の確認がとれた通路が";
	mes "公開されたのです。";
	mes "これで、ビフロストとモロク、";
	mes "エルディカスティスへの";
	mes "移動が楽になりました。";
	next;
	mes "[遠征隊員]";
	mes "次元の狭間は時間と空間が";
	mes "歪んだ場所です。";
	mes "もし道に迷ってしまったら";
	mes "どこに放り出されるかわかりません。";
	mes "調査済みの地域のみ利用してください。";
	next;
	mes "[遠征隊員]";
	mes "くれぐれも気を付けてください。";
	close;
}

moc_fild22b,223,203,3	script	次元の狭間の案内員#gk04	707,{
	mes "[遠征隊員]";
	mes "次元の狭間内部に行きたい方は";
	mes "次元移動機を利用してください。";
	mes "次元の狭間内部は";
	mes "まだ探索中の通路もありますので";
	mes "道に迷わない様に気を付けて下さい。";
	close;
}

bif_fild01,314,155,5	script	次元の狭間の案内員#gk05	852,{
	mes "[遠征隊員]";
	mes "次元の狭間内部に行きたいのですか？";
	mes "それなら、そこにある次元移動機を";
	mes "使ってください。";
	next;
	switch(select("次元の狭間について聞く","近くに怪しい人がいる","会話終了")) {
	case 1:
		mes "[遠征隊員]";
		mes "少し前から、私たちは次元の狭間を";
		mes "利用して、こことミッドガルドを";
		mes "行き来しているじゃありませんか？";
		mes "こちらの狭間も、そういった";
		mes "通路のようなものだと";
		mes "考えていただければいいと思います。";
		next;
		mes "[遠征隊員]";
		mes "次元の狭間の中を通ることで";
		mes "いろいろな場所に移動する方法が";
		mes "発見されたんです。";
		next;
		mes "[遠征隊員]";
		mes "それで、安定性の確認がとれた通路が";
		mes "公開されたのです。";
		mes "これで、ビフロストとモロク、";
		mes "エルディカスティスへの";
		mes "移動が楽になりました。";
		next;
		mes "[遠征隊員]";
		mes "次元の狭間は時間と空間が";
		mes "歪んだ場所です。";
		mes "もし道に迷ってしまったら";
		mes "どこに放り出されるかわかりません。";
		mes "調査済みの地域のみ利用してください。";
		next;
		mes "[遠征隊員]";
		mes "中で迷子になると救出は困難ですので";
		mes "くれぐれも気を付けてください。";
		close;
	case 2:
		mes "[遠征隊員]";
		mes "怪しい人？";
		mes "あ……はい、あの人ですね。";
		mes "エルディカスティスの偉い方が";
		mes "狭間の調査に派遣した人のようです。";
		next;
		mes "[遠征隊員]";
		mes "なるべく摩擦が起きない様に";
		mes "ラフィネ族達が努力をしています。";
		mes "それ以上の詳しいことは";
		mes "私もよく分かりません。";
		close;
	case 3:
		mes "‐あなたはその場から離れた‐";
		close;
	}
}

bif_fild01,320,154,3	script	次元の狭間の案内員#gk06	852,{
	mes "[遠征隊員]";
	mes "次元の狭間内部に行きたい方は";
	mes "次元移動機を利用してください。";
	mes "次元の狭間内部は";
	mes "まだ探索中の通路もありますので";
	mes "道に迷わない様に気を付けて下さい。";
	close;
}

dic_fild02,236,33,5	script	次元の狭間の案内員#gk07	852,{
	mes "[遠征隊員]";
	mes "次元の狭間内部に行きたいのですか？";
	mes "それなら、そこにある次元移動機を";
	mes "使ってください。";
	next;
	if(select("次元の狭間について聞く","会話終了") == 2) {
		mes "‐あなたはその場から離れた‐";
		close;
	}
	mes "[遠征隊員]";
	mes "少し前から、私たちは次元の狭間を";
	mes "利用して、こことミッドガルドを";
	mes "行き来しているじゃありませんか？";
	mes "こちらの狭間も、そういった";
	mes "通路のようなものだと";
	mes "考えていただければいいと思います。";
	next;
	mes "[遠征隊員]";
	mes "次元の狭間の中を通ることで";
	mes "いろいろな場所に移動する方法が";
	mes "発見されたんです。";
	next;
	mes "[遠征隊員]";
	mes "それで、安定性の確認がとれた通路が";
	mes "公開されたのです。";
	mes "これで、ビフロストとモロク、";
	mes "エルディカスティスへの";
	mes "移動が楽になりました。";
	next;
	mes "[遠征隊員]";
	mes "次元の狭間は時間と空間が";
	mes "歪んだ場所です。";
	mes "もし道に迷ってしまったら";
	mes "どこに放り出されるかわかりません。";
	mes "調査済みの地域のみ利用してください。";
	next;
	mes "[遠征隊員]";
	mes "中で迷子になると救出は困難ですので";
	mes "くれぐれも気を付けてください。";
	close;
}

dic_fild02,239,36,3	script	次元の狭間の案内員#gk08	852,{
	mes "[遠征隊員]";
	mes "次元の狭間内部に行きたい方は";
	mes "次元移動機を利用してください。";
	mes "次元の狭間内部は";
	mes "まだ探索中の通路もありますので";
	mes "道に迷わない様に気を付けて下さい。";
	close;
}

-	script	次元移動機#Hero1	10007,{
	mes "‐次元移動機がある。";
	mes "　次元の狭間内部に行きますか？‐";
	next;
	if(select("はい","いいえ") == 2) {
		mes "‐あなたは次元移動機から離れた‐";
		close;
	}
	mes "‐次元の狭間内部に移動します‐";
	close2;
	set .@name$,strnpcinfo(2);
	if(.@name$ == "gate01")
		warp "dali",141,82;
	else if(.@name$ == "gate02")
		warp "dali",119,59;
	else if(.@name$ == "gate03")
		warp "dali",44,94;
	else if(.@name$ == "gate04")
		warp "dali",40,134;
	end;
}

mid_camp,210,292,0		duplicate(次元移動機#Hero1)	次元移動機#gate01	10007
moc_fild22b,222,200,3	duplicate(次元移動機#Hero1)	次元移動機#gate02	10007
bif_fild01,318,159,3	duplicate(次元移動機#Hero1)	次元移動機#gate03	10007
dic_fild02,241,31,3		duplicate(次元移動機#Hero1)	次元移動機#gate04	10007

dali,149,82,0	warp	#dari_to_midcamp		3,3,mid_camp,210,289
dali,122,48,0	warp	#dari_to_moc_fild22b	3,3,moc_fild22b,227,200
dali,39,87,0	warp	#dari_to_bif_fild01		3,3,bif_fild01,318,155
dali,35,139,0	warp	#dari_to_dic_fild02		3,3,dic_fild02,237,32

dali,109,94,5	shop	猫の手サービス雑貨商人	496,611,1750,1065,579,602

dali,112,95,3	script	猫の手サービス物流管理	496,{
	mes "[物流管理ニャン]";
	mes "いらっしゃいにゃん。";
	mes "この不思議な場所で";
	mes "あなた達の品物を管理している";
	mes "物流管理ニャンだにゃん。";
	mes "倉庫利用するのにゃん？";
	next;
	if(select("倉庫を利用する-200Zeny","やめる") == 2) {
		mes "[物流管理ニャン]";
		mes "また来てくれにゃん。";
		close;
	}
	if(Zeny < 200) {
		// 未調査
		mes "[物流管理ニャン]";
		mes "お金が足りないにゃん！";
		close;
	}
	mes "[物流管理ニャン]";
	mes "倉庫を開くにゃん。";
	set Zeny,Zeny-200;
	openstorage;
	close;
}

dali,56,126,3	script	サファ族の派遣員#dali01	449,{
	mes "[ミヨ]";
	mes "ここの次元の狭間は";
	mes "エルディカスティスの南にある。";
	mes "カミダル山麗南部と繋がっています。";
	mes "調査のため、ここに寄りましたけど";
	mes "本当に信じられません。";
	next;
	mes "[ミヨ]";
	mes "すぐ隣にはラフィネ族がいるし……";
	mes "……うむ……";
	mes "あ、心配しないでください。";
	mes "こんな所で戦いたくありませんから。";
	close;
OnInit:
	waitingroom "カミダル山麓南部方面",0;
	end;
}

dali,51,104,5	script	スプレンディット兵士#da	447,{
	mes "[スプレンディット兵士]";
	mes "この空間内もビフロストと同じで";
	mes "不思議な力が働いているようですね。";
	mes "他の種族との意志疎通が容易なので";
	mes "助かります。";
	next;
	mes "[スプレンディット兵士]";
	mes "ここはビフロスト南部と繋がっている";
	mes "次元の狭間です。";
	mes "スプレンディット前線基地まで";
	mes "移動できます。";
	next;
	mes "[スプレンディット兵士]";
	mes "それと、これをうまく利用すると";
	mes "サファ族の首都まで素早い進撃が";
	mes "可能かもしれません。";
	mes "ふふ……冗談ですよ。";
	next;
	mes "[スプレンディット兵士]";
	mes "マヨルからなるべく摩擦は避けて";
	mes "協力するようにと言われたので、";
	mes "そんな事はしませんよ。";
	mes "現時点での敵はサファ族ではなく、";
	mes "魔王ですから。";
	close;
OnInit:
	waitingroom "ビフロスト南部方面",0;
	end;
}

dali,137,87,3	script	連合駐屯地派遣員#dali03	997,{
	mes "[連合駐屯地派遣員]";
	mes "こちらの次元の狭間は";
	mes "ヨトゥンヘイムの連合キャンプと";
	mes "繋がっています。";
	next;
	mes "[連合駐屯地派遣員]";
	mes "安定的な移動が可能になるように";
	mes "数百回の実験の末に";
	mes "設置されたものなので";
	mes "安心してください。";
	close;
OnInit:
	waitingroom "ミッドガルド連合軍駐屯地方面",0;
	end;
}

dali,122,60,3	script	モロク兵士#dali04	707,{
	mes "[モロク兵士]";
	mes "こっちはモロクに発生している";
	mes "次元の狭間と繋がっています。";
	mes "ミッドガルドに戻れる一番の近道です。";
	mes "狭間の周辺は相変わらずですが……";
	close;
OnInit:
	waitingroom "モロク東部方面",0;
	end;
}
