//= Athena Script ==============================================================
// Ragnarok Online Aldebaran Town Script
//==============================================================================

//============================================================
// Shop
//------------------------------------------------------------
aldeba_in,94,56,5	shop	道具商人	83,501,502,503,504,506,645,656,601,602,611,610
aldeba_in,28,54,0	shop	武器商人	49,1201,1204,1207,1210,1213,1216,1219,1222
aldeba_in,20,60,0	shop	防具商人	101,2228,2103,2105,2307,2309,2312,2314,2316,2505,2405,2628,2627
alde_alche,38,184,2	shop	材料販売商人	755,7143,7141,7140,6248,6250,6251,6255,6261,6262,6297
aldeba_in,22,47,4	shop	武器商人	713,1146,1245

//============================================================
// アルデバランNPC
//------------------------------------------------------------
aldebaran,113,70,4	script	精錬工マンスタ	48,{
	mes "[マンスタ]";
	mes "僕の家は以前";
	mes "ゲフェンにあったんだけど";
	mes "昨年の冬、ここアルデバランに";
	mes "引越してきたんです。";
	next;
	if(select("^3355FF「精錬」^000000 について","会話をやめる")==2) {
		mes "[マンスタ]";
		mes "まだお父さんの";
		mes "精錬所がどこにあるか";
		mes "知らない人が多いけど";
		mes "このアルデバランでも";
		mes "お父さんに有名になって";
		mes "もらいたいです。";
		close;
	}
	mes "[マンスタ]";
	mes "お父さんは";
	mes "ブラックスミスの街、ゲフェンでも";
	mes "かなり有名な人でした。";
	mes "でも、ここは母の故郷なので";
	mes "引っ越すことにしたんです……";
	next;
	mes "[マンスタ]";
	mes "僕もたまにお父さんの仕事を";
	mes "手伝ってるんですよ。";
	mes "最近習っているのは";
	mes "精錬成功確率についてです。";
	next;
	mes "[マンスタ]";
	mes "レベル 1 の武器は";
	mes "+7 まで安全に精錬できます。";
	mes "レベル 2 は +6";
	mes "そして、レベル 3 の武器は";
	mes "+5 まではわりと安全に";
	mes "精錬が可能です。";
	next;
	mes "[マンスタ]";
	mes "レベル4 の武器の場合";
	mes "+4までは安全に精錬できます。";
	mes "防具の場合、通常 +4 まで";
	mes "安全に精錬可能です。";
	close;
}

aldebaran,64,104,4	script	精錬ジジ	55,{
	mes "[クアトロ]";
	mes "このアルデバランに";
	mes "ゲフェンではちょっと名が通った";
	mes "鍛冶屋が来たという噂を聞いたが……";
	next;
	if(select("武器レベルについて","有名な鍛冶屋について")==2) {
		mes "[クアトロ]";
		mes "なんでも、奥さんの体が弱くて";
		mes "アルデバランの周辺にしか生えない";
		mes "薬草を毎日飲まなきゃならない";
		mes "みたいなんだ。";
		next;
		mes "[クアトロ]";
		mes "息子はいい奴で親の仕事を";
		mes "一緒にやってるみたいだな…";
		mes "あいつ、いい鍛冶屋になるぜ。";
		close;
	}
	mes "[クアトロ]";
	mes "そういえば";
	mes "武器のレベルにより";
	mes "追加される攻撃力の強さが";
	mes "差があるらしい……";
	next;
	mes "[クアトロ]";
	mes "レベル1の場合、2";
	mes "レベル2の場合、3";
	mes "レベル3の場合は、5！";
	mes "レベル4の場合は……なんと、7!!";
	close;
}

aldebaran,49,93,4	script	武器レベル青年	83,{
	mes "[ミレアル]";
	mes "知ってますか？";
	mes "武器の中にはレベル3より上の";
	mes "レベル4の武器が存在することを ！";
	next;
	mes "[ミレアル]";
	mes "店などでは買うことができない";
	mes "このレベル4の武器は ";
	mes "ボスモンスターを倒した時に";
	mes "すごく低い確率で";
	mes "出ることがあるんです！";
	close;
}

aldebaran,81,61,4	script	貝狩り少女	101,{
	mes "[ジョセー]";
	mes "海岸の近くや砂浜で";
	mes "貝狩りをするのはとても楽しいの。";
	next;
	if(select("貝狩りについて","会話をやめる")==2) {
		mes "[ジョセー]";
		mes "いつか、有名な琥珀貝を";
		mes "食べるのが夢なの！";
		mes "ちょっと危ないかも知れないけど……";
		mes "でもそれくらいの価値は";
		mes "あると思うのよ。";
		close;
	}
	mes "[ジョセー]";
	mes "砂浜や水たまりなどで";
	mes "泡がボコボコ";
	mes "出てくるのを見つけたら";
	mes "そこを掘ってみてね。";
	mes "大抵、貝がその中にもぐっているの。";
	next;
	mes "[ジョセー]";
	mes "でもねー";
	mes "殻がとても硬くて";
	mes "凶暴で触ることさえできない";
	mes "陸で動く貝があります！";
	next;
	mes "[ジョセー]";
	mes "その貝はアンバーナイトといって";
	mes "プロンテラ西部地方の";
	mes "海岸で見ることができるの";
	mes "下手に触ったりしたら";
	mes "逃げるしかないの。";
	mes "すごくこわいんだから……";
	close;
}

aldebaran,46,129,4	script	運河青年	97,{
	mes "[パナマ]";
	mes "アルデバランは";
	mes "ミッドガルド大陸で";
	mes "知らぬものがいないほど";
	mes "有名な運河の都市です。";
	next;
	if(select("運河の都市について","会話をやめる")==2) {
		mes "[パナマ]";
		mes "水が綺麗でしょう？";
		mes "田舎だからですって？";
		mes "それを言っちゃ終わりでしょう……";
		mes "…………";
		mes "まぁ、ゆっくりしていってください。";
		close;
	}
	mes "[パナマ]";
	mes "運河は…";
	mes "内陸に入る船舶の航行や";
	mes "農地への水の供給、";
	mes "または排水に使うために";
	mes "人工的に作った水路です。";
	next;
	mes "[パナマ]";
	mes "運河は一般的に";
	mes "交通機関の一部として作られます。";
	mes "大抵、陸地を掘って作るか、埋立の時";
	mes "残した水路を使うこともあります。";
	next;
	mes "[パナマ]";
	mes "川に手を加えて作ったから";
	mes "ただの人工水路でも運河だと";
	mes "呼ばれる事もあるのでしょう。";
	close;
}

aldebaran,67,154,4	script	山道青年	98,{
	mes "[アイゼンバーグ]";
	mes "ミョルニール山脈、フェイヨンの森";
	mes "どちらも険しい地形で有名です。";
	next;
	switch(select("ミョルニール山脈について","フェイヨンの森について","会話をやめる")) {
	case 1:
		mes "[アイゼンバーグ]";
		mes "ルーンミッドガッツ王国の";
		mes "首都であり騎士団のある";
		mes "プロンテラ。";
		mes "マジシャン・ウィザードと";
		mes "ブラックスミスの街";
		mes "ゲフェン。";
		next;
		mes "[アイゼンバーグ]";
		mes "そのどちらの街から来るとしても";
		mes "必ず越えなければならない山脈";
		mes "ミョルニール！";
		next;
		mes "[アイゼンバーグ]";
		mes "そしてモンクの聖カピトーリナ";
		mes "修道院からこのアルデバランに";
		mes "来るとしても、必ずミョルニールを";
		mes "通らなければなりません。";
		mes "ミョルニール山脈は";
		mes "標高が高く地形が険しい上に";
		next;
		mes "[アイゼンバーグ]";
		mes "凶暴で、強力なモンスターが";
		mes "そばを通るだけで襲ってくるので";
		mes "ここまで来るのはすごく";
		mes "大変だったでしょう？";
		mes "本当にお疲れ様でした。";
		close;
	case 2:
		mes "[アイゼンバーグ]";
		mes "モロクの砂漠からアルベルタへ";
		mes "そして、フェイヨンに行くためには";
		mes "必ずフェイヨンの森を";
		mes "通らなければなりません。";
		next;
		mes "[アイゼンバーグ]";
		mes "アルベルタとフェイヨンの間に";
		mes "位置するこの森は";
		mes "まるで迷路のように";
		mes "入り組んでいるので気をつけないと";
		mes "迷子になってしまうのです。";
		next;
		mes "[アイゼンバーグ]";
		mes "アルベルタの森ではなく";
		mes "フェイヨンの森と";
		mes "呼ばれる理由は……";
		next;
		mes "[アイゼンバーグ]";
		mes "アーチャーの町、フェイヨンは";
		mes "外部勢力からの侵略を防ぐため";
		mes "居住地の中心をなるべく";
		mes "深くて険しい山の中に";
		mes "したかったのです。";
		next;
		mes "[アイゼンバーグ]";
		mes "そういうわけで森の名は";
		mes "開かれた港町アルベルタではなく";
		mes "森の奥の町フェイヨンの名前で";
		mes "呼ばれるのではないかと思います。";
		close;
	case 3:
		mes "[アイゼンバーグ]";
		mes "10エリアを越える広大な山脈が";
		mes "他の地方から来る旅行者の";
		mes "悩みの種ですが……";
		mes "おかげで運河や錬金術など";
		mes "個性的で神秘的な雰囲気を";
		mes "守ることができました。";
		close;
	}
}

aldebaran,90,170,4	script	スロット青年	47,{
	mes "[エプティアル]";
	mes "武器と防具の中には";
	mes "スロット(Slot)という";
	mes "穴が開いているものがあって";
	mes "そこにはモンスターを倒すと稀に落とす";
	mes "カードを挿すことができます。";
	next;
	switch(select("スロットの数について","モンスターカードとスロットの関係","会話をやめる")) {
	case 1:
		mes "[エプティアル]";
		mes "一般の商店で売っている";
		mes "武器や防具より";
		mes "モンスターから戦利品で得た";
		mes "アイテムのほうがスロットが";
		mes "多いのですよ。";
		next;
		mes "[エプティアル]";
		mes "そういうアイテムにはカードが";
		mes "普通のものより多く付けられるから";
		mes "アイテムとしての価値も";
		mes "グッと上がるんですよ。";
		close;
	case 2:
		mes "[エプティアル]";
		mes "スロットに1回挿したカードは";
		mes "2度と外せませんから";
		mes "注意して使ったほうがいいです。";
		mes "スロットにカードを付ける前に";
		mes "もう1度よく考えてみてください。";
		close;
	case 3:
		mes "[エプティアル]";
		mes "モンスターが落とすカードを";
		mes "お持ちでしょうか？";
		close;
	}
}

aldebaran,117,181,4	script	プラコン青年	48,{
	mes "[ジュアリー]";
	mes "装備アイテムの中で";
	mes "一番低いGRADE(レベル1)の";
	mes "武器を精錬するためには";
	mes "「プラコン」という";
	mes "金属が必要です。";
	next;
	switch(select("プラコンについて","プラコンに関するアドバイス","会話をやめる")) {
	case 1:
		mes "[ジュアリー]";
		mes "プラコンという金属は";
		mes "昔からミッドガルド全域に渡って";
		mes "多くの人々が利用してきた";
		mes "一般的な精錬用金属だと";
		mes "いわれています。";
		next;
		mes "[ジュアリー]";
		mes "鋼鉄や様々な貴重な鉱石に比べて";
		mes "そんなに高い強度を持ってはいませんが";
		mes "一般人でも簡単に手に入れられるという";
		mes "汎用性から精錬用金属の中では";
		mes "一番はやっていますね。";
		next;
		mes "[ジュアリー]";
		mes "このプラコンはモンスターから";
		mes "戦利品として手に入れたり";
		mes "鍛冶屋がいる精錬所で";
		mes "精錬用の金属販売を専門にしている";
		next;
		mes "[ジュアリー]";
		mes "精錬工から購入することで";
		mes "手に入れることができます。";
		mes "ある程度レベルが上がって";
		mes "上級レベルの武器が使えるようになり";
		next;
		mes "[ジュアリー]";
		mes "プラコンが手に入っても";
		mes "使い道がなくなって困ったら…";
		mes "さっさと売ってしまいましょう。";
		mes "なんと、100 Zenyの現金に";
		mes "なります♪";
		close;
	case 2:
		mes "[ジュアリー]";
		mes "プラコンを持っているモンスターは";
		mes "意外に多いと聞いたことがあります。";
		mes "1度、探してみたらどうですか？";
		mes "損ではないと思いますよ。";
		next;
		mes "[ジュアリー]";
		mes "この前、休日に";
		mes "隣の酒場のマスターと";
		mes "狩りに出かけたんですが";
		mes "猪の子供から出ましたよ。";
		close;
	case 3:
		mes "[ジュアリー]";
		mes "あぁー";
		mes "上質のプラコンが欲しいなぁ……";
		close;
	}
}

aldebaran,121,231,4	script	錬金術青年	49,{
	mes "[ケミアル]";
	mes "錬金術師というのは";
	mes "古代アルデバランで";
	mes "非金属を人工的な手段で";
	mes "金属に変換することを目標とした";
	mes "化学、科学者達のことだ。";
	next;
	switch(select("フェイヨン錬金術について","錬金術師について","……","会話をやめる")) {
	case 1:
		mes "[ケミアル]";
		mes "古代アルデバランと時を同じくして";
		mes "フェイヨンでは道教の思想から生まれた";
		mes "飲む事で長生きができ";
		mes "仙人になれるといわれた";
		mes "「丹」というものがあった。";
		mes "その丹から錬金術が誕生したんだ。";
		next;
		mes "[ケミアル]";
		mes "やがて、その技術で";
		mes "金を作ろうとする思想が生まれた。";
		mes "科学中心の錬金術とは違い";
		mes "主に呪術的な手法をとる";
		mes "それがフェイヨン錬金術なんだ。";
		next;
		mes "[ケミアル]";
		mes "しかしフェイヨン地方の";
		mes "錬金術は発達しなかった……";
		mes "アルデバランとは違い";
		mes "周辺の自然環境が悪く";
		mes "錬金術研究に必要な材料が";
		mes "常に不足していたんだ。";
		next;
		mes "[ケミアル]";
		mes "だから今、ミッドガルドにおいて";
		mes "「錬金術」と関連のある場所は";
		mes "このアルデバランの";
		mes "錬金術師ギルドだけになってしまった。";
		close;
	case 2:
		mes "[ケミアル]";
		mes "錬金術師という者達は";
		mes "科学、化学両面に長けていて";
		mes "様々な物質を混ぜる事によって";
		mes "機能的なアイテムを";
		mes "作り出す事ができたそうだ。";
		close;
	case 3:
		mes "[ケミアル]";
		mes "退屈そうだな、それじゃ……";
		mes "モンスターカードとスロットに関する";
		mes "話をちょっとしようじゃないか。";
		mes "モンスターカードを";
		mes "1枚でも持っていれば";
		mes "もう知っているかも知れないけど";
		next;
		mes "[ケミアル]";
		mes "各カードには挿すスロットの";
		mes "装備位置の指定があり";
		mes "必ず鎧なら鎧、剣なら剣";
		mes "その種類のアイテム以外には";
		mes "挿すことができないから";
		mes "注意するように。";
		next;
		mes "[ケミアル]";
		mes "例えばポリンカードを例にすると";
		mes "ポリンカードには説明文に";
		mes "「LUK+2、完全回避+1」という";
		mes "効果数値と装着部位、";
		mes "「鎧」と表示されている。";
		next;
		mes "[ケミアル]";
		mes "従って、このカードを";
		mes "スロットが多くあるからといって";
		mes "武器等に付けようとしても";
		mes "不可能ということなんだ。";
		next;
		mes "[ケミアル]";
		mes "また、街で売っている防具には";
		mes "スロットが付いていない物が多く";
		mes "反対にモンスターから";
		mes "戦利品として得た";
		mes "防具にはスロットがあるから";
		mes "有効に活用した方がいいよ。";
		next;
		mes "[ケミアル]";
		mes "あ、モンスターカードを";
		mes "装備品につける方法は";
		mes "まず装備を外して";
		mes "所持アイテムウィンドウ上において";
		mes "挿したいカードをダブルクリック！";
		mes "すると……";
		next;
		mes "[ケミアル]";
		mes "持っている装備品の中から";
		mes "挿すことができる";
		mes "アイテムのリストが表示されるから";
		mes "後は選択するだけなんだ。";
		mes "簡単でしょ？";
		close;
	case 4:
		mes "[ケミアル]";
		mes "ミッドガルド錬金術といえば";
		mes "アルデバラン錬金術師ギルド!!";
		mes "錬金術よ！永遠なれ!!";
		close;
	}
}

aldebaran,86,228,4	script	子供	62,{
	mes "[べべ]";
	mes "この前、家で飼ってる子豚の";
	mes "「べべベン」をつれて";
	mes "ミョルニール山脈の方に";
	mes "お散歩に行ってきたの。";
	mes "べべベンは猪の一種で";
	mes "とても可愛いピンク色の子豚なの。";
	next;
	switch(select("べべベンの散歩の話をしてくれ","ミョルニール山脈の雰囲気は？","会話をやめる")) {
	case 1:
		mes "[べべ]";
		mes "山道に沿ってずーっと登っていたら";
		mes "きれいな大きい花があったの";
		mes "匂いをかごうと近寄ったら……";
		mes "その大きい花が僕とべべベンを";
		mes "いじめるの。";
		next;
		mes "[べべ]";
		mes "本当にビックリして遠くまで離れて";
		mes "石を投げたりしたの。";
		mes "でもびくともしなかったの。";
		mes "すっごく丈夫な奴だったの。";
		next;
		mes "[べべ]";
		mes "それでちょっとだけ近寄ってみたの。";
		mes "そしたら花が人の顔をしてたの！";
		mes "歯で噛み噛みしてきたの！";
		mes "信じられる？";
		close;
	case 2:
		mes "[べべ]";
		mes "ミョルニール山脈は";
		mes "各種の華麗な植物と";
		mes "可愛く見えるけど手ごわい昆虫や";
		mes "動物がいっぱいなの。";
		mes "花・蟲・特に蜂と蝶……";
		mes "蛾などに手をだしちゃダメなの。";
		next;
		mes "[べべ]";
		mes "大抵の獣と蟲は";
		mes "先に攻撃しなければ";
		mes "向こうから攻撃してくることは";
		mes "なかなかないから……";
		close;
	case 3:
		mes "[べべ]";
		mes "あれ、 べべベンはどこに行ったの？";
		mes "べべベン！こっちにくるの!!";
		mes "くるのっ!!!!";
		close;
	}
}

aldebaran,159,242,4	script	昆虫ジジ	119,{
	mes "[ストーロング]";
	mes "ミョルニール山脈……";
	mes "山道を歩いていれば";
	mes "誰でもわかる事実がある。";
	mes "それは昆虫の習性によって";
	mes "強さが分かれてるって事や。";
	mes "君は知ってるんか？";
	next;
	if(select("昆虫について","会話をやめる")==2) {
		mes "[ストーロング]";
		mes "いくら綺麗で弱そうに見えるからゆうて";
		mes "テントウ虫みたいな昆虫でも";
		mes "下手に手ぇ出したら";
		mes "痛い目見るで。";
		mes "ミョルニール山脈の大自然の力を";
		mes "なめたらあかん！";
		close;
	}
	mes "[ストーロング]";
	mes "蜂や、蝶、蛾などは";
	mes "花と花の間を飛びまわって";
	mes "蜜を吸って生きてるやろう？";
	mes "花粉を運んで花の受粉を";
	mes "手伝ったりするかわいい奴らなんや。";
	mes "普段はな……";
	next;
	mes "[ストーロング]";
	mes "だからといって";
	mes "奴らをなめたらあかんで。";
	mes "生存するために";
	mes "奴らも奴らなりの戦闘力を";
	mes "持つように進化したってわけや。";
	next;
	mes "[ストーロング]";
	mes "また、こういう昆虫を";
	mes "食ってる肉食昆虫がおってな";
	mes "カマキリやクモ";
	mes "そしてムカデなどが";
	mes "その代表的な奴らやな。";
	next;
	mes "[ストーロング]";
	mes "こういう肉食モンスターは";
	mes "ちょっと強くなった程度じゃ";
	mes "1匹相手するのも";
	mes "しんどくて、えらい強いで！";
	mes "特に赤芋虫はあなどれんわ！";
	next;
	mes "[ストーロング]";
	mes "最悪やで！";
	mes "へたすりゃ一発で終わりや！";
	mes "それでも不幸中の幸いなのは";
	mes "その<アルギオペ>の視力が";
	mes "めっちゃ悪くて、遠くやったら";
	mes "全然気づかへんいうことやな。";
	close;
}

aldebaran,60,70,4	script	乙女	69,{
	mes "[セニョリータ シルビア]";
	mes "このアルデバランのどこかに";
	mes "カプラサービス本社があると聞いて";
	mes "プロンテラから、ここアルデバランまで";
	mes "遠い道を来ました。";
	mes "そ……それなのに……エーン……";
	next;
	mes "[セニョリータ シルビア]";
	mes "探しはじめてから";
	mes "5時間も経つのに……";
	mes "いったいどこにあるのか……";
	mes "私は…こんなに賢く見えても";
	mes "道探しは苦手です……";
	next;
	mes "[セニョリータ シルビア]";
	mes "……あ、そうだ。";
	mes "私、役に立ちそうな情報を";
	mes "知ってるんだけど、教えてほしい？";
	next;
	if(select("教えて","別にいいや")==2) {
		mes "[セニョリータ シルビア]";
		mes "そう……";
		close;
	}
	mes "[セニョリータ シルビア]";
	mes "モンスターからの戦利品が";
	mes "装備アイテムの場合";
	mes "装備品のはずなのに";
	mes "装備できない事があります。";
	mes "そんな時には……じゃーん!!";
	mes "^3355FFむーしーめーがーねー（拡大鏡）^000000";
	next;
	mes "[セニョリータ シルビア]";
	mes "拡大鏡を使えば、商人や";
	mes "ブラックスミスがいなくても";
	mes "簡単にアイテム鑑定が";
	mes "できるんですよー！";
	close;
}

aldebaran,93,80,4	script	足の長い青年	48,{
	mes "[ディュウカティー]";
	mes "ここアルデバランは、";
	mes "町中に水路があって";
	mes "あちこちにきれいな水が流れる、";
	mes "秀麗な景観が自慢です。";
	mes "し・か・し";
	next;
	mes "[ディュウカティー]";
	mes "昨夜、家族に黙って";
	mes "彼女に会いに行く途中";
	mes "足を踏み外してあの水路に落ちて";
	mes "真夜中のデートが台無しになって";
	mes "しまったんです。";
	next;
	if(select("あらら、残念でしたね……","ふーん……それで？")==2) {
		mes "[ディュウカティー]";
		mes "ううう……";
		mes "僕を馬鹿なやつだと";
		mes "思っているんでしょう？";
		close;
	}
	mes "[ディュウカティー]";
	mes "それで昨日、防具店に勤めている";
	mes "僕の彼女から聞いた話なんだけど";
	mes "普通の商店で売っている";
	mes "アイテムより";
	next;
	mes "[ディュウカティー]";
	mes "モンスターから";
	mes "戦利品で得たアイテムの方が";
	mes "良い性能である事が";
	mes "多いらしいんです。";
	next;
	mes "[ディュウカティー]";
	mes "専門用語で「スロットが多い」";
	mes "って言われてるそうです。";
	mes "僕は何のことだか";
	mes "さっぱりわからないけど……";
	close;
}

aldebaran,180,46,4	script	東洋人	88,{
	mes "[ハジュシャク]";
	mes "私はフェイヨンという森の町から";
	mes "来た観光客です。";
	mes "ここは……町中に水が流れていて";
	mes "とても涼しいですね。";
	next;
	mes "[ハジュシャク]";
	mes "ところで……、この水……";
	mes "飲んでも平気でしょうか？";
	mes "もう……飲んじゃってるんですけど……";
	next;
	if(select("会話を進める","やめる")==1) {
		mes "[ハジュシャク]";
		mes "それは置いておいて、";
		mes "私は旅行をしていて、";
		mes "アルデバランに着く前に";
		mes "ある高位な魔術師に";
		mes "聞いた話ですが……";
		next;
		mes "[ハジュシャク]";
		mes "実体がない^3355FF念属性^000000モンスターの場合";
		mes "無属性攻撃、もしくは魔法で";
		mes "ダメージを与える事は";
		mes "すごく難しいとおっしゃっていました。";
		next;
		mes "[ハジュシャク]";
		mes "この情報が役に立てば幸いです。";
		mes "それじゃ……";
	}
	else {
		mes "[ハジュシャク]";
		mes "ここ、アルデバランは";
		mes "周りの環境はとても良いし";
		mes "水がとっても美味しいですよね。";
		mes "さっき飲んだ水も心配なさそうです。";
	}
	close;
}

aldebaran,212,122,4	script	アルデバラン市民	97,{
	mes "[シリンダー]";
	mes "いらっしゃい！";
	mes "ここはアルデバランです！";
	mes "我々アルデバラン市民は";
	mes "あなたを歓迎致します！";
	mes "……";
	next;
	mes "[シリンダー]";
	mes "大げさですかね？市民代表……";
	mes "ウーム、ではまずは私一人だけでも";
	mes "あなたを歓迎します！";
	next;
	if(select("会話を進める","やめる")==2) {
		mes "[シリンダー]";
		mes "アルデバランは綺麗で";
		mes "壮大なミョルニール山脈に";
		mes "囲まれた、すばらしい運河の都市です。";
		close;
	}
	mes "[シリンダー]";
	mes "あ、そういえばこの前";
	mes "面白い奴を見ましたよ。";
	mes "このアルデバランを囲む";
	mes "ミョルニール山脈で。";
	next;
	mes "[シリンダー]";
	mes "ミョルニールの森付近で";
	mes "天使の翼を持つポリンを見ました！";
	mes "……本当ですよ！！";
	next;
	mes "[シリンダー]";
	mes "何匹かの普通のポリンと";
	mes "遊んでいました。";
	mes "天使の翼を持つポリンだなんて……";
	mes "天使ポリン？";
	close;
}

aldebaran,145,123,4	script	村の少女	101,{
	mes "[キャムシャフト]";
	mes "この世界のどこかに";
	mes "^3355FF「アサシンギルド」^000000";
	mes "というところがあって";
	mes "音も立てずに忍び寄り、人を殺める";
	mes "技術を教えてくれるといいます。";
	mes "それ…";
	next;
	mes "[キャムシャフト]";
	mes "違法ですよね？";
	mes "……";
	mes "違法なのに、技術を習得するのに";
	mes "費用がかかるんでしょうか？";
	next;
	if(select("会話を進める","やめる")==2) {
		mes "[キャムシャフト]";
		mes "無料で教えて貰うことなんて";
		mes "できないでしょうね……";
		mes "うーん……";
		close;
	}
	mes "[キャムシャフト]";
	mes "話が変わるけど……";
	mes "羽がついていて飛行能力がある";
	mes "モンスターの多くは";
	mes "移動、攻撃速度が速くて";
	mes "こちらの攻撃を当てるのが";
	mes "すごく難しいのです。";
	next;
	mes "[キャムシャフト]";
	mes "奴らを相手にするためには";
	mes "もっと正確に敵を捕らえる為に";
	mes "DEX（技）が必要よ！";
	close;
}


//============================================================
// アルデバラン室内NPC
//------------------------------------------------------------
aldeba_in,232,241,4	script	市民	48,{
	mes "[RS125]";
	mes "私の名が非人間的で、";
	mes "私の言葉使いが冷たいと感じても";
	mes "私を恐れないでください。";
	mes "心だけは暖かいですから……";
	next;
	mes "[RS125]";
	mes "私の胸の中には普通の人とは違って……";
	mes "2つの心臓が脈打っています。";
	mes "その鼓動が耳に焼きつき……";
	mes "止まることになっても……";
	mes "私はアルデバランの";
	mes "未来のために走ります。";
	next;
	if(select("事情を聞く","会話をやめる")==2) {
		mes "[RS125]";
		mes "いつかは、世界一周の旅に出たいと";
		mes "思っています。港湾都市アルベルタで";
		mes "見る海はどれほど素晴らしいでしょう。";
		mes "来年のアルデバランターボトラックが";
		mes "終わったら、兄と世界一周に";
		mes "挑戦したいです。";
		close;
	}
	mes "[RS125]";
	mes "…もう、3年が経ちました……";
	mes "私の兄である<996>は";
	mes "アルデバラン代表の短距離陸上選手で";
	mes "一時は「アルデバランのペコペコ」と";
	mes "呼ばれるほどの速い足が自慢でした。";
	mes "4年に一度、アルデバランで開かれる";
	next;
	mes "[RS125]";
	mes "「アルデバランターボトラック」では";
	mes "兄の姿を一目見ようと集まる";
	mes "世界各地のファン達のおかげで……";
	mes "マネージャーだった私が";
	mes "ノイローゼになる程でしたから";
	mes "その人気は本当にすごかったです……";
	next;
	mes "[RS125]";
	mes "しかし……";
	mes "永遠などというものはありません……";
	mes "フェイヨンという、うっそうとした ";
	mes "森のなかにある村の少女が";
	mes "兄の独走を止めました。";
	next;
	mes "[RS125]";
	mes "兄はその後、無理な訓練により";
	mes "心臓に障害をかかえ";
	mes "今、病床で私を見つめています。";
	next;
	mes "[RS125]";
	mes "私は、このアルデバランの";
	mes "未来を背負い、兄の志を継ぐのです！";
	mes "見ていて下さい……";
	mes "必ず「フェイヨンのそよ風」";
	mes "<ハバナ>に勝って見せます！";
	close;
}

aldeba_in,223,121,4	script	強面なおじさん	63,{
	mes "[顔付きの怖いおじさん]";
	mes "おい、人の家に勝手に入るんじゃねぇ";
	mes "君、ほんと失礼だな。";
	mes "何の用でこんなとこに来て";
	mes "この俺に声をかけるのだ？";
	next;
	mes "[顔付きの怖いおじさん]";
	mes "フッフッフッ、知ってるよ、知ってる";
	mes "俺が現実世界に存在すると";
	mes "勘違いしたな…";
	next;
	if(select("話を続ける","やめる")==2) {
		mes "[顔付きの怖いおじさん]";
		mes "早く消えろ！";
		mes "警察なら捜査令状を……";
		mes "我が一族の人間だというなら";
		mes "お尻の蒙古斑を見せてみろ！";
		close;
	}
	mes "[顔付きの怖いおじさん]";
	mes "既に知っているかもしれないが";
	mes "この世界には";
	mes "傭兵システムというものがある。";
	mes "そして、俺もその傭兵の一人……";
	next;
	mes "[顔付きの怖いおじさん]";
	mes "傭兵の役割とシステムは単純だ。";
	mes "金で一緒に戦ってくれる奴を";
	mes "探すんだよ……";
	mes "もちろん実力がある奴の値段は高い。";
	next;
	mes "[顔付きの怖いおじさん]";
	mes "……つまんない話はやめて";
	mes "良い傭兵を選ぶ方法を";
	mes "簡単に教えてやるよ。";
	next;
	mes "[顔付きの怖いおじさん]";
	mes "まず、鼻がきれいかどうか良く見ろ";
	mes "良い傭兵であるかは";
	mes "鼻をみれば分かる。";
	mes "いつも濡れている方が良い。";
	mes "鼻が乾いていれば";
	mes "そいつは、風邪をひいている……";
	next;
	mes "[顔付きの怖いおじさん]";
	mes "そして足首が細い方が良い";
	mes "やはり傭兵といったら";
	mes "細い足首と真っ白な首筋だぜ！";
	mes "そしてロングヘアーに、金のかかった";
	mes "セッティングパーマなら最高だろ?!";
	next;
	mes "[顔付きの怖いおじさん]";
	mes "最後に、傭兵というものは……";
	mes "サービス業だ！";
	mes "お客様が最後の一滴まで、楽しんで";
	mes "飲めるように、そばで接待するのが";
	mes "本物の傭兵だ！もちろん、おしぼりは";
	mes "忘れずに代えてあげること！";
	close;
}

aldeba_in,219,61,4	script	紳士風なおじさん	109,{
	mes "[顔付きの良いおじさん]";
	mes "横の部屋にいる顔付きの怖い";
	mes "おじさんの話は気にするな。";
	mes "一昨年、私設傭兵の訓練所で";
	mes "木の実を取りに木に登り";
	mes "頭から落ちて、あの有り様よ……";
	next;
	mes "[顔付きの良いおじさん]";
	mes "ずーっと話しっぱなしで";
	mes "私も困っているんだ……";
	mes "頭が痛いよ！";
	close;
}

aldeba_in,152,47,4	script	おおげさ青年	97,{
	mes "[おおげさ青年]";
	mes "た、た、大変なんですよ！";
	mes "僕が飼っていた、僕の可愛い";
	mes "「ひよこ」がっ！";
	mes "家を出て行ってしまいました!!";
	next;
	if(select("ひよこの名前は？","……")==2)
		close;
	mes "[おおげさ青年]";
	mes "「すごいピッキ」といいます……";
	mes "え〜ん、えんえん";
	mes "どうすればいいんだ〜";
	mes "どうか、ぼくの可愛い";
	mes "ピッキちゃんを探してください〜";
	next;
	if(select("なんだ！ ありふれた名前じゃないか？","……")==1) {
		mes "[おおげさ青年]";
		mes "僕を馬鹿にしてるんですね！";
		mes "僕には兄弟がいなくて可愛いひよこを";
		mes "兄弟がわりに思ってたんです！";
		mes "う、うわぁぁぁん!!";
		close;
	}
	mes "[おおげさ青年]";
	mes "僕を馬鹿にしてるんですね……";
	mes "僕には兄弟がいなく、て可愛いひよこを";
	mes "兄弟がわりに思ってたんです……";
	mes "う、うっうっうっ……うっうっ……";
	close;
}

aldeba_in,156,179,4	script	マスター	61,{
	mes "[マスター]";
	mes "ここアルデバランには";
	mes "カプラサービスの本社があります。";
	mes "そこのねえちゃん達が時々";
	mes "このバーに遊びにくるんですけど";
	mes "すごく愉快な家族なんですよ♪";
	next;
	mes "[マスター]";
	mes "さあ、ここで君に質問！";
	mes "君の好みの女性を調べる";
	mes "「サンキューマスター」の時間です！";
	mes "あ、えっと、別にあなたが男性でも";
	mes "女性でも、それは全然構いません。";
	next;
	mes "[マスター]";
	mes "普段、ああっ、このねぇちゃん！";
	mes "いや、こっちのねぇちゃん！";
	mes "すばらしいー！！";
	mes "…と思ってたカプラねえちゃんを";
	mes "選ぶのです！";
	next;
	if(select("おお、面白そうジャン！","うーん、やめときます……")==2) {
		mes "[マスター]";
		mes "アアーッ!!昨夜、寝ないで作った";
		mes "この素晴らしいアンケートを";
		mes "無視するなんて！";
		mes "なんて冷たい人だ!!";
		close;
	}
	mes "[マスター]";
	mes "さあ、では紹介します！";
	mes "よく考えてお選びくださいっ！";
	next;
	mes "[マスター]";
	mes "元祖カプラねえちゃん";
	mes "クラシックな青い髪が美しい";
	mes "(1)番、^3355FF「ディフォルテー」^000000!!";
	mes "ポニーテールの落ち着いたイメージで";
	mes "純情な男児を魅了する";
	mes "(2)番、^5533FF「テーリング」^000000!!";
	next;
	mes "[マスター]";
	mes "ロングストレートヘアーが";
	mes "チャームポイント！";
	mes "しなやかな肢体 ! フェイヨン出身の";
	mes "(3)番、^555555「ソリン」^000000!!";
	next;
	mes "[マスター]";
	mes "ボーイッシュなショートカットで";
	mes "元気一杯、活気あふれる";
	mes "(4)番、^1133DD「ビニット」^000000!!";
	mes "冷静で、落ち着いた雰囲気";
	mes "OLスタイルで行こう！眼鏡が似合う";
	mes "(5)番、^33FF55「グラリス」^000000!!";
	next;
	mes "[マスター]";
	mes "ツインテールの女の子";
	mes "幼く見えても仕事はバッチリ！";
	mes "(6)番、^AAAA00「Ｗ」^000000！！";
	next;
	mes "[マスター]";
	mes "協賛：(株)カプラサービス";
	mes "(有)ジョンダイベント";
	mes "以上です。";
	next;
	switch(select("(1) ディフォルテー","(2) テーリング","(3) ソリン","(4) ビニット","(5) グラリス","(6) Ｗ")) {
	case 1:
		mes "[マスター]";
		mes "ふむ、古いものが好きなあなたは";
		mes "とっても馬鹿正直な人！";
		mes "新しいものを受け入れてみて下さい！";
		mes "現実から逃げたって無駄です！";
		close;
	case 2:
		mes "[マスター]";
		mes "あなたは集中力がないですね！";
		mes "あなたのパートナーまで";
		mes "注意散漫だとしたら……";
		mes "周りに迷惑ばかりかけることに";
		mes "なるでしょう！";
		close;
	case 3:
		mes "[マスター]";
		mes "あれもこれもダメだったら……";
		mes "悲観的なことばかり";
		mes "考えるのはよくありません。";
		mes "人生に意欲を持ってください！";
		close;
	case 4:
		mes "[マスター]";
		mes "いつまで夢の中で";
		mes "理想を探し続けるつもりですか？";
		mes "現実をしっかり見なさい！";
		close;
	case 5:
		mes "[マスター]";
		mes "皮肉屋のあなたに一言！";
		mes "心を開きなさい！";
		mes "一人ぼっちでいないで ！";
		close;
	case 6:
		mes "[マスター]";
		mes "こ、こら！";
		mes "幼い恋人を欲しがる、あなた！";
		mes "は、犯罪です！";
		close;
	}
}

//============================================================
// カプラサービス本社NPC
//------------------------------------------------------------
aldebaran,58,225,3	script	カプラ職員	116,{
	mes "[カプラ職員]";
	mes "こんにちは。";
	mes "カプラサービスです。";
	mes "こちらは、";
	mes "カプラサービスの本社です。";
	mes "通常営業外の";
	mes "サービスを行っております。";
	next;
	mes "[カプラ職員]";
	mes "何かございましたら、";
	mes "中にいるカプラ職員に";
	mes "お問い合わせください。";
	close;
}

aldeba_in,79,161,7	script	カプラ職員	115,{
	mes "[カプラ職員]";
	mes "いらっしゃいませ" +strcharinfo(0)+ "様。";
	mes "当カプラサービスをご利用いただき";
	mes "獲得されたポイントと、";
	mes "カプラコインを交換しております。";
	next;
	mes "[カプラ職員]";
	mes "カプラポイント";
	mes "^7D0781500p ^000000でカプラコインと交換か、";
	mes "^7D07813000p ^000000でチャンスにチャレンジすることが";
	mes "できます。";
	next;
	mes "[カプラ職員]";
	mes "お客様の獲得ポイントは";
	mes "^FF0000" +KAFRA_PIT+ "^000000 です。";
	mes "次の中からご希望の品物を";
	mes "お選びください。";
	next;
	switch(select("500p = カプラコイン 1 枚","3000p = チャンス","取り消し")) {
	case 1:
		mes "[カプラ職員]";
		mes "一度に交換できるのは";
		mes "10枚までとなります。";
		mes "もし取り消す場合は、";
		mes "「0」とおっしゃってください。";
		mes "カプラコイン何枚と";
		mes "交換しますか？";
		next;
		input .@num;
		if(.@num == 0) {
			mes "[カプラ職員]";
			mes "取り消しました。";
			close;
		} else if(.@num < 0 || .@num > 10) {
			mes "[カプラ職員]";
			mes "数が正しくないようです。";
			close;
		}
		if(KAFRA_PIT < 500*.@num) {
			mes "[カプラ職員]";
			mes "カプラポイントが足りません。";
			mes "お手持ちのポイント数を";
			mes "確認なさってからお越しください。";
			close;
		}
		if(checkitemblank() == 0) {
			mes "‐所持アイテムの種類数が多い為";
			mes "　危険です。";
			mes "　所持アイテムを減らしてから、";
			mes "　再度話しかけてください‐";
			close;
		}
		set KAFRA_PIT,KAFRA_PIT-500*.@num;
		getitem 6367,.@num;
		mes "[カプラ職員]";
		mes "ご利用ありがとうございました。";
		close;
	case 2:
		if(KAFRA_PIT < 3000) {
			mes "[カプラ職員]";
			mes "カプラポイントが足りません。";
			mes "お手持ちのポイント数を";
			mes "確認なさってからお越しください。";
			close;
		}
		mes "[カプラ職員]";
		mes "^0000FFチャンス！^000000";
		next;
		mes "[カプラ職員]";
		mes "それでは、お客様の運だめしと";
		mes "まいりましょう。";
		mes "準備はよろしいですか？";
		next;
		mes "[カプラ職員]";
		mes "こちらの抽選機を";
		mes "回してください。";
		next;
		switch(rand(3)) {
		case 0: mes "ジャラジャラ……"; break;
		case 1: mes "ガラガラガラ……"; break;
		case 2: mes "ポロッ カツッ カツン……"; break;
		}
		next;
		mes "[カプラ職員]";
		mes "はい、でましたね〜";
		mes "えっと……";
		next;
		mes "[カプラ職員]";
		mes "^FF0000おっ……これは^000000";
		next;
		if(checkitemblank() == 0) {
			mes "[カプラ職員]";
			mes "お客様、少々荷物を持ちすぎて";
			mes "おりませんか？";
			mes "その状態では賞品を交換しても";
			mes "お持ちになれません。";
			next;
			mes "[カプラ職員]";
			mes "お手数ですが、カプラサービスを";
			mes "ご利用になり、種類数を";
			mes "減らすようお願い致します。";
			close;
		}
		if(MaxWeight-Weight < 1000) {
			mes "[カプラ職員]";
			mes "お客様、少々荷物を持ちすぎて";
			mes "おりませんか？";
			mes "その状態では賞品を交換しても";
			mes "お持ちになれません。";
			next;
			mes "[カプラ職員]";
			mes "お手数ですが、カプラサービスを";
			mes "ご利用になり、残り重量が";
			mes "^0000FF1100^000000 程になるよう荷物を";
			mes "減らすようお願い致します。";
			close;
		}
		set KAFRA_PIT,KAFRA_PIT-3000;
		set .@prize,rand(1,100);
		if(.@prize == 100) {
			mes "[カプラ職員]";
			mes "1等〜";
			mes "1等賞です〜";
			mes "賞品は ^00FF00カプラヘアバンド 1個！^000000";
			getitem 12399,1;
			break;
		} else if(.@prize >= 98 && .@prize < 100) {
			mes "[カプラ職員]";
			mes "2等〜";
			mes "2等賞です〜";
			mes "賞品は ^00FF00豪華な宝箱 1個！^000000";
			getitem 12399,1;
			break;
		} else if(.@prize >= 95 && .@prize < 98) {
			mes "[カプラ職員]";
			mes "3等〜";
			mes "3等賞です〜";
			mes "賞品は ^00FF00カプラコイン 10枚！^000000";
			getitem 6367,10;
			break;
		} else if(.@prize >= 89 && .@prize < 95) {
			mes "[カプラ職員]";
			mes "4等〜";
			mes "4等賞です〜";
			mes "賞品は ^00FF00カプラコイン 6枚！^000000";
			getitem 6367,6;
			break;
		} else if(.@prize >= 63 && .@prize < 89) {
			mes "[カプラ職員]";
			mes "5等〜";
			mes "5等賞です〜";
			mes "賞品は ^00FF00カプラコイン 3枚！^000000";
			getitem 6367,3;
			break;
		} else if(.@prize >= 37 && .@prize < 63) {
			mes "[カプラ職員]";
			mes "6等〜";
			mes "6等賞です〜";
			mes "賞品は ^00FF00カプラコイン 2枚！^000000";
			getitem 6367,2;
			break;
		} else {
			mes "[カプラ職員]";
			mes "残念〜";
			mes "残念賞です〜";
			mes "賞品は ^00FF00カプラコイン 1枚！^000000";
			getitem 6367,1;
			break;
		}
		next;
		mes "[カプラ職員]";
		mes "おめでとうございます〜";
		mes "ご利用ありがとうございました！";
		next;
		mes "[カプラ職員]";
		mes "また多くのポイントを集め";
		mes "られるよう願っております。";
		mes "いつも (株)カプラサービスを";
		mes "ご利用いただきありがとう";
		mes "ございます。";
		close;
	case 3:
		mes "[カプラ職員]";
		mes "また多くのポイントを集め";
		mes "られるよう願っております。";
		mes "いつも (株)カプラサービスを";
		mes "ご利用いただきありがとう";
		mes "ございます。";
		close;
	}
}

aldeba_in,84,166,4	script	カプラサービス	117,{
	cutin "kafra_01",2;
	mes "[カプラディフォルテー]";
	mes "いらっしゃいませ！";
	mes "カプラサービスにおける";
	mes "初代カプラ職員、";
	mes "「ディフォルテー」と申します！";
	mes "よろしくお願いします。";
	next;
	mes "[カプラディフォルテー]";
	mes "我がカプラサービスは、いつでも";
	mes "お客様に満足していただくために";
	mes "誠実、信用、正直を三大原則として";
	mes "徹底した訓練と管理を通じてお客様の";
	mes "お世話をさせて頂いております。";
	next;
	switch(select("あれ、カプラ利用券は〜？","さよなら","迷子って？")) {
	case 1:
		mes "[カプラディフォルテー]";
		mes "ギクッ！";
		mes "申し訳ございません……";
		mes "カプラ利用券につきましては、";
		mes "本社の決定により廃止することに";
		mes "なりました……";
		mes "本当にごめんなさい……";
		break;
	case 2:
		mes "[カプラディフォルテー]";
		mes "ご利用頂き、ありがとうございました！";
		mes "お相手はカプラディフォルテーでした。";
		break;
	case 3:
		mes "[カプラディフォルテー]";
		mes "本社での研修を終えた子を";
		mes "実地研修に向かわせたのですが……";
		mes "素直で可愛くて、頑張り屋の";
		mes "とっても良い子なんです。";
		mes "道に迷ってしまったのでしょう……";
		next;
		mes "[カプラディフォルテー]";
		mes "まだ研修中なので、きっとどこかで";
		mes "一人で困っていると思うのです。";
		mes "ああ、かわいそうに";
		mes "どうしたらいいのでしょう……";
		break;
	}
	close2;
	cutin "kafra_01",255;
	end;
}

aldeba_in,83,233,4	script	カプラサービス	116,{
	cutin "kafra_02",2;
	mes "[カプラテーリング]";
	mes "……ディフォルテーねぇちゃんは";
	mes "いっつも、ああなんだから！";
	mes "研修生は転送してあげればいいのに";
	mes "これも研修の内なんて言って";
	mes "歩いていかせるから";
	mes "迷子になっちゃうのよ。";
	next;
	mes "[カプラテーリング]";
	mes "そのくせ、こんなことになったら";
	mes "一番心配しちゃって";
	mes "おろおろしてるのよ！";
	next;
	switch(select("あなたは心配じゃないの？","研修って何？")) {
	case 1:
		mes "[カプラテーリング]";
		mes "あら、私だってもちろん";
		mes "心配してますよ！";
		mes "でも、研修生といえども";
		mes "私達カプラ職員はしっかり";
		mes "教育されているので";
		mes "そんなに心配要らないんです。";
		break;
	case 2:
		mes "[カプラテーリング]";
		mes "私達カプラ職員は";
		mes "皆様をしっかりとサポートする為";
		mes "様々な研修を受けています。";
		mes "その一環で、実地研修に";
		mes "行く途中の研修生が";
		mes "迷子になってしまったんです。";
		break;
	}
	close2;
	cutin "kafra_02",255;
	end;
}

aldeba_in,28,238,4	script	カプラサービス	115,{
	cutin "kafra_03",2;
	mes "[カプラソリン]";
	mes "こんにちは。";
	mes "お客様、ミッドガルド大陸の外界に";
	mes "何があるかご存知ですか？";
	next;
	mes "[カプラソリン]";
	mes "私、すっごく知りたいんです。";
	mes "いったい何があるのかしら？";
	mes "港街のアルベルタに派遣されたら";
	mes "何か面白い話でも聞けるのかな？";
	next;
	switch(select("外の世界に興味あるの？","大陸の外界って？")) {
	case 1:
		mes "[カプラソリン]";
		mes "もちろんですっ！";
		mes "私達カプラサービスは";
		mes "どんなところでも";
		mes "サービスを提供させていただこうと";
		mes "考えておりますので！";
		next;
		mes "[カプラソリン]";
		mes "……でも";
		mes "個人的に興味もありますよ。";
		mes "遠い異国の街……";
		mes "どんな素敵なものが";
		mes "売っているのかしら？";
		mes "ああ、行ってみたいです。";
		break;
	case 2:
		mes "[カプラソリン]";
		mes "詳しくはわからないのですが";
		mes "遠く海を越えたところに";
		mes "島か、大陸があって";
		mes "そこには変わった文化の";
		mes "国、街があるそうです。";
		mes "噂なんですけどね！";
		break;
	}
	close2;
	cutin "kafra_03",255;
	end;
}

aldeba_in,142,238,4	script	カプラサービス	114,{
	cutin "kafra_04",2;
	mes "[カプラビニット]";
	mes "いらっしゃいませ！";
	mes "カプラ「ビニット」です。";
	mes "お客様にだけお教えする";
	mes "とっておきのお話！";
	next;
	mes "[カプラビニット]";
	mes "実は……";
	mes "我がカプラサービスはですねー";
	mes "以前は、カプラサービスという";
	mes "名前じゃなかったんですー";
	mes "さあ、ではなんだったでしょう？";
	next;
	mes "[カプラビニット]";
	mes "ジャーーーン！ それはっ！";
	mes "カ！フ！(RRRR)";
	mes "ハッ、携帯が……、ちょっと失礼。";
	next;
	mes "[カプラビニット]";
	mes "はいっ、ビニットです。";
	mes "あっ、本部長！はいっ！はいっ！";
	mes "……はいっ！";
	mes "はい！？";
	next;
	mes "[カプラビニット]";
	mes "あっ、いいえ！";
	mes "あ……、なんでもありません！";
	mes "はいっ！分かりました!!";
	next;
	mes "[カプラビニット]";
	mes "（ピッ）";
	mes "ふぅ……";
	mes "えへへ……";
	next;
	mes "[カプラビニット]";
	mes "あの……、お客さん";
	mes "少し前のことは";
	mes "あの……なかったことにしませんか？";
	mes "えへへー";
	mes "ね？";
	close2;
	cutin "kafra_04",255;
	end;
}

aldeba_in,96,181,4	script	カプラサービス	113,{
	cutin "kafra_05",2;
	mes "[カプラグラリス]";
	mes "カプラ「グラリス」です。";
	mes "お客様、なにかご用ですか？";
	next;
	switch(select("ミッドガルド大陸の外界ついて聞く","特に用はない")) {
	case 1:
		mes "[カプラグラリス]";
		mes "ここはミッドガルド大陸";
		mes "シュバルツバルド共和国の";
		mes "最南端に位置する国境都市";
		mes "アルデバランです。";
		next;
		mes "[カプラグラリス]";
		mes "ミッドガルド大陸には";
		mes "ミッドガッツ王国や";
		mes "シュバルツバルド共和国の他に";
		mes "いくつかの国がありますが、";
		mes "大陸の外界には何があるのか";
		mes "わかっていません。";
		break;
	case 2:
		mes "[カプラグラリス]";
		mes "そうですか…";
		break;
	}
	close2;
	cutin "kafra_05",255;
	end;
}

aldeba_in,91,244,4	script	カプラサービス	112,{
	cutin "kafra_06",2;
	mes "[カプラW]";
	mes "こんにちはぁー！";
	mes "カプラサービスのかわいい末っ子！";
	mes "カプラタイプ「W」ですー";
	next;
	mes "[カプラW]";
	mes "私は新人なのでカプラサービスで";
	mes "みなさんにお会いするようになったのは";
	mes "最近ですが、いつも最善を";
	mes "つくしてがんばっています！";
	mes "どうか、宜しくお願いしますー";
	next;
	switch(select("いくつ ?","やめる")) {
	case 1:
		mes "[カプラW]";
		mes "……";
		mes "もうっ！";
		mes "子供扱いしないでくださいよっ!!";
		break;
	case 2:
		mes "[カプラW]";
		mes "我がカプラサービスでは";
		mes "最！上！のサービスを提供するために";
		mes "最！善！をつくしております。";
		mes "ご利用頂き、ありがとうございました。";
		break;
	}
	close2;
	cutin "kafra_06",255;
	end;
}

//============================================================
// アルデバラン時計塔NPC
//------------------------------------------------------------
aldebaran,143,136,4	script	管理人怪人A	89,{
	mes "[管理人怪人A]";
	mes "俺は「地楽委」所属";
	mes "アルデバランの時計塔を";
	mes "管理する怪人Aである。";
	mes "君、この時計塔に関心があるか？";
	mes "どうなんだ？いい情報が欲しいか？";
	next;
	switch(select("時計塔について教えて","「 地楽委 」とは？","やめる")) {
	case 1:
		mes "[管理人怪人A]";
		mes "この時計塔の中はある装置を通じて";
		mes "すべてのフロアーが繋がっている…";
		mes "いわば「階層連動ワープシステム」が";
		mes "設置されているんだ。";
		next;
		mes "[管理人怪人A]";
		mes "時計塔のあちこちに存在する";
		mes "ワープシステムは";
		mes "お互い連動してる場所もあるが";
		mes "どこに飛ばされるかわからない";
		mes "「ランダムワープ 」も存在する。";
		next;
		mes "[管理人怪人A]";
		mes "ヒントを教えてやろうか？";
		mes "このランダムワープはミニマップには";
		mes "緑色で表示されてるんだ。";
		mes "ミニマップをよく見ておけ！";
		mes "時計と楽しい時間を過ごすがいい。";
		mes "フフフ……";
		close;
	case 2:
		mes "[管理人怪人A]";
		mes "君、「地楽委」について";
		mes "聞いたことがあるのかね？";
		next;
		if(select("はい、よく知ってます！","何それ？")==1) {
			mes "[管理人怪人A]";
			mes "ふふふ…偉い！";
			mes "すでに我等の名声が無名の";
			mes "冒険家にまで知られているとは！";
			mes "本当に嬉しい！嬉しいぞ！！";
			mes "記念に君にこれを差し上げよう！";
			next;
			mes "[管理人怪人A]";
			mes "げっ…、ど、どこに置いたっけな…";
			mes "うーん…、あっ！";
			mes "4階の管理室に忘れたみたいだな。";
			mes "悪いな、また会う時までには";
			mes "用意しておくことにしよう。";
			mes "じゃ、またな！";
		}
		else {
			mes "[管理人怪人A]";
			mes "ったく、まだ我等「地楽委」を";
			mes "知らない者がいるとはな……";
			mes "俺が特別に教えよう、「地楽委」は";
			mes "「地上楽園建設推進委員会」の略で";
			mes "この時計塔も我等の作品である。";
			mes "ん？なんだその顔は？本当だぞ！";
			next;
			mes "[管理人怪人A]";
			mes "以前はグラストヘイムの";
			mes "設計、施工も進めていたのである。";
			mes "これからもいろんなところで";
			mes "我等の偉大なる業績を";
			mes "見ることができるであろう！";
			mes "……もしかして、……疑ってる？";
		}
		close;
	case 3:
		mes "[管理人怪人A]";
		mes "知りたいことがあれば";
		mes "何でも聞きたまえ。";
		close;
	}
}

c_tower3,10,249,4	script	番人	84,{
	mes "[番人リク]";
	mes "アルデバラン名物";
	mes "キナセ - ブルガリノ";
	mes "時計塔にようこそ.";
	mes "地上 4階からは";
	mes "立入り禁止なので";
	mes "入らないで下さい。";
	next;
	switch(select("時計塔について","4階について","4階に移動する","対話を終了")) {
	case 1:
		mes "[番人リク]";
		mes "錬金術師のメッカーアルデバラン！";
		mes "はるか昔 . 伝説の";
		mes "3 大錬金術師に呼ばれた";
		mes "ブルケサイマー";
		mes "ピリペバリセズ";
		mes "そして…";
		next;
		mes "[番人リク]";
		mes "ロメロスペシャレ！";
		mes "この偉大なる建造物は";
		mes "彼らが建設したものです";
		mes "ここまで来る途中に";
		mes "ある程度感じられたかも知れないけど";
		mes "この時計塔は平凡ではない。";
		next;
		mes "[番人リク]";
		mes "古代の錬金術を基にして";
		mes "相当な否らしい呪術的な";
		mes "構造になっているのです.";
		mes "明確な目的なしに";
		mes "ウロウロまわったりしたら";
		next;
		mes "[番人リク]";
		mes "時計塔の番人である魔物によって";
		mes "大変なことに遭うのでしょう。";
		mes "くれぐれも気をつけてください…";
		close;
	case 2:
		mes "[番人リク]";
		mes "古代錬金術師は";
		mes "魔物と他国の兵士から";
		mes "何かを守るため";
		mes "錬金術的装置を製作して";
		mes "4階に入る扉を封印しました.";
		mes "その扉を通過するためには";
		next;
		mes "[番人リク]";
		mes "ある鍵が必要です。";
		mes "その鍵はこの時計塔で所々を";
		mes "彷徨っている";
		mes "恐ろしい魔物が";
		mes "持っているということです..";
		next;
		mes "[番人リク]";
		mes "その鍵は古代錬金術の集約体で";
		mes "1回使ってしまうと";
		mes "呪術が解けて消えるように";
		mes "作られている。";
		next;
		mes "[番人リク]";
		mes "もし貴方がその鍵を";
		mes "手に入れたら";
		mes "私に見せてください.";
		mes "鍵を持つその者こそ";
		mes "この扉が通れる";
		next;
		mes "[番人リク]";
		mes "資格がある者！";
		mes "貴方の運を";
		mes "試して貰おう…";
		mes "……";
		close;
	case 3:
		if(countitem(7026)) {
			mes "[番人リク]";
			mes "うむ!貴方には普通ではないオーラが";
			mes "感じられたが";
			mes "やはり私の予想通りですね。";
			mes "さあ、この扉を通っても良いです。";
			mes "幸運を祈ります…";
			close2;
			delitem 7026,1;
			warp "c_tower4",185,44;
			end;
		}
		mes "[番人リク]";
		mes "……";
		mes "貴方はこの扉を通る";
		mes "資格が無いです ..";
		mes "古代の錬金術師が";
		mes "許さない限り";
		mes "この先に進むのは無理だと思います.";
		close;
	case 4:
		mes "[番人リク]";
		mes "この時計塔は";
		mes "古代3大錬金術師の";
		mes "誠意と心が宿っている所…";
		mes "時計塔の内部飾りなどに";
		mes "手を出さないで下さい.";
		close;
	}
}

alde_dun03,264,16,4	script	番人	101,{
	mes "[番人アイ]";
	mes "アルデバラン名物";
	mes "キナセ - ブルガリノ";
	mes "時計塔にようこそ.";
	mes "地下 4階からは";
	mes "立入り禁止なので";
	mes "入らないで下さい。";
	next;
	switch(select("時計塔について","4階について","4階に移動する","対話を終了")) {
	case 1:
		mes "[番人アイ]";
		mes "錬金術師のメッカーアルデバラン！";
		mes "はるか昔 . 伝説の";
		mes "3 大錬金術師に呼ばれた";
		mes "ブルケサイマー";
		mes "ピリペバリセズ";
		mes "そして…";
		next;
		mes "[番人アイ]";
		mes "ロメロスペシャレ！";
		mes "この偉大なる建造物は";
		mes "彼らが建設したものよ。";
		mes "ここまで来る途中に";
		mes "ある程度感じられたかも知れないけど";
		mes "この時計塔は平凡ではないの。";
		next;
		mes "[番人アイ]";
		mes "古代の錬金術を基にして";
		mes "相当な否らしい呪術的な";
		mes "構造になっているの.";
		mes "明確な目的なしに";
		mes "ウロウロまわったりしたら";
		next;
		mes "[番人アイ]";
		mes "時計塔の番人である魔物によって";
		mes "大変なことに遭うのよ。";
		mes "お気をつけなさい…";
		close;
	case 2:
		mes "[番人アイ]";
		mes "古代錬金術師は";
		mes "魔物と他国の兵士から";
		mes "何かを守るため";
		mes "錬金術的装置を製作して";
		mes "4階に入る扉を封印したのよ.";
		mes "その扉を通過するためには";
		next;
		mes "[番人アイ]";
		mes "ある鍵が必要よ。";
		mes "その鍵はこの時計塔で所々を";
		mes "彷徨っている";
		mes "恐ろしい魔物が";
		mes "持っていると聞いたわ.";
		next;
		mes "[番人アイ]";
		mes "その鍵は古代錬金術の集約体で";
		mes "1回使ってしまうと";
		mes "呪術が解けて消えるように";
		mes "作られているの。";
		next;
		mes "[番人アイ]";
		mes "もし貴方がその鍵を";
		mes "手に入れたら";
		mes "私に見せてくれないかしら？.";
		mes "鍵を持つその者こそ";
		mes "この扉が通れる";
		next;
		mes "[番人アイ]";
		mes "資格がある者なの。";
		mes "貴方の運を";
		mes "試して行ってらっしゃい。";
		mes "……";
		close;
	case 3:
		if(countitem(7027)) {
			mes "[番人アイ]";
			mes "うん!貴方には普通ではないオーラが";
			mes "感じられて";
			mes "私はこうなると予想したのよ。";
			mes "さあ、この扉を通っても良いのよ。";
			mes "貴方に幸運を祈る…";
			close2;
			delitem 7027,1;
			warp "alde_dun04",79,267;
			end;
		}
		mes "[番人アイ]";
		mes "……";
		mes "貴方はこの扉を通る";
		mes "資格が無いのよ ..";
		mes "古代の錬金術師が";
		mes "許さない限り";
		mes "この先に進むのは無理なの。";
		close;
	case 4:
		mes "[番人アイ]";
		mes "この時計塔は";
		mes "古代3大錬金術師の";
		mes "誠意と心が宿っているもの…";
		mes "時計塔の内部飾りなどに";
		mes "手を出さないで…";
		close;
	}
}

//============================================================
// 捻じれた時間の時計塔NPC
//------------------------------------------------------------
c_tower1,232,222,5	script	べルザミン・ボタン#ct	968,{
	if(BaseLevel < 150) {
		mes "[べルザミン・ボタン]";
		mes "^FF0000捻じれた時間の時計塔^000000について";
		mes "知っていますか？";
		next;
		mes "[べルザミン・ボタン]";
		mes "私はそこから来ました。";
		mes "そこにいたせいで私の時間にもまた";
		mes "深刻なねじれが";
		mes "発生してしまったんです。";
		next;
		mes "[べルザミン・ボタン]";
		mes "時間を思いのまま操れる";
		mes "モンスター達がいる場所です。";
		mes "もっと強くなってから";
		mes "また来てください。";
		next;
		mes "‐この先に進むには";
		mes "　^0000FFBaseLv150以上^000000が必要です‐";
		close;
	}
	mes "[べルザミン・ボタン]";
	mes "^FF0000捻じれた時間の時計塔^000000について";
	mes "知っていますか？";
	mes "私はそこから来ました。";
	mes "そこにいたせいで私の時間にもまた";
	mes "深刻なねじれが";
	mes "発生してしまったんです。";
	next;
	mes "[べルザミン・ボタン]";
	mes "そこは時間を思いのままに操れる";
	mes "モンスター達がいる場所で、";
	mes "年齢や記憶、環境を取り巻く時間の";
	mes "すべてがねじられてしまいます。";
	next;
	mes "[べルザミン・ボタン]";
	mes "あなたの時間さえも危険に";
	mes "さらされる可能性があります。";
	mes "試しに行ってみようなんて";
	mes "考えない方が良いですよ。";
	next;
	switch(select("行かない","捻じれた時間の時計塔1階に行く","捻じれた時間の時計塔2階に行く","捻じれた時間の時計塔3階に行く","捻じれた時間の時計塔4階に行く")) {
	case 1:
		mes "[べルザミン・ボタン]";
		mes "ほっ……いい判断です。";
		mes "強力なモンスター達が";
		mes "徘徊しているとても危険な場所です。";
		mes "早くここから離れて";
		mes "安全な場所に避難してください。";
		close;
	case 2:
		set .@map$,"c_tower1_";
		set .@x,235;
		set .@y,223;
		break;
	case 3:
		set .@map$,"c_tower2_";
		set .@x,268;
		set .@y,26;
		break;
	case 4:
		set .@map$,"c_tower3_";
		set .@x,65;
		set .@y,147;
		break;
	case 5:
		set .@map$,"c_tower4_";
		set .@x,185;
		set .@y,44;
		break;
	}
	mes "[べルザミン・ボタン]";
	mes "本当に行くんですか？";
	mes "危険な選択ですよ。";
	next;
	mes "[べルザミン・ボタン]";
	mes "あまりにも危険なので";
	mes "入場料^0000FF10,000Zeny^000000が必要になります。";
	next;
	switch(select("入場する　-10,000Zeny-","やめる","どうして入場料が必要なの？")) {
	case 1:
		if(Zeny < 10000) {
			// 未調査
			mes "[べルザミン・ボタン]";
			mes "お金が足りないようですね？";
			close;
		}
		mes "[べルザミン・ボタン]";
		mes "どうか私のように時間に流されないで";
		mes "無事でいてください……。";
		close2;
		set Zeny, Zeny-10000;
		warp .@map$,.@x,.@y;
		end;
	case 2:
		mes "[べルザミン・ボタン]";
		mes "それでいいんです。";
		mes "強力なモンスター達が";
		mes "徘徊しているとても危険な場所です。";
		mes "早くここから離れて";
		mes "安全な場所に避難してください。";
		close;
	case 3:
		mes "[べルザミン・ボタン]";
		mes "冒険者の安全のために";
		mes "ここで一日中、危険な場所の存在を";
		mes "知らせているのですから、";
		mes "対価が必要になるのは";
		mes "しょうがないことです。";
		emotion 4,"";
		close;
	}
}

c_tower1,232,222,5	script	べルザミン・ボタン#ct1	962,{
	mes "[べルザミン・ボタン]";
	mes "多分、私に出会ったことがある";
	mes "人ですよね？";
	next;
	mes "[べルザミン・ボタン]";
	mes "今とは違う姿で";
	mes "ここではないまた別の場所にて";
	mes "お会いしたんでしょうね。";
	next;
	switch(select("ここについて知りたい","外に出させてください") == 1) {
	case 1:
		mes "[べルザミン・ボタン]";
		mes "ここで何を経験して、";
		mes "何を知ったのか、あなたは私に";
		mes "説明することができますか？";
		next;
		mes "[べルザミン・ボタン]";
		mes "私も同じです。";
		mes "目的も知らないまま、";
		mes "ここで立ち続ける人が";
		mes "まさにあなたになるかもしれません。";
		next;
		mes "[べルザミン・ボタン]";
		mes "もう戻る時間です。";
		mes "どうかあなたの時間を";
		mes "大事にしてください。";
		next;
		if(select("もう少し留まる","外に出る") == 1) {
			mes "[べルザミン・ボタン]";
			mes "ここの雰囲気が";
			mes "気に入ったようですね。";
			mes "では、いくらでも。";
			close;
		}
		break;
	case 2:
		mes "[べルザミン・ボタン]";
		mes "お別れの時間です。";
		mes "好きな飲み物はありますか？";
		next;
		break;
	}
	mes "[べルザミン・ボタン]";
	mes "コップに入っている飲み物を";
	mes "思い浮かべてみてください。";
	mes "スプーンを使ってゆっくりと";
	mes "飲み物をかき混ぜます。";
	mes "そして色が少しずつ変わっていくのを";
	mes "眺めます。";
	close2;
	warp "c_tower1",235,223;
	end;
}
c_tower2,274,26,3	duplicate(べルザミン・ボタン#ct1)	べルザミン・ボタン#ct2	962

c_tower3,59,148,5	script	べルザミン・ボタン#ct3	574,{
	mes "[べルザミン・ボタン]";
	mes "多分、私に出会ったことがある";
	mes "人ですよね？";
	next;
	mes "[べルザミン・ボタン]";
	mes "今とは違う姿で";
	mes "ここではないまた別の場所にて";
	mes "お会いしたんでしょうね。";
	next;
	switch(select("あなたはいったい誰ですか？","外に出してください")) {
	case 1:
		mes "[べルザミン・ボタン]";
		mes "よく聞かれる質問です。";
		mes "後日、やはりあなたも";
		mes "嫌というほど聞くことになるでしょう。";
		next;
		mes "[べルザミン・ボタン]";
		mes "本を一枚一枚めくっていくと、";
		mes "結末に到達します。";
		mes "これもまた同じでしょう。";
		next;
		mes "[べルザミン・ボタン]";
		mes "もう戻る時間です。";
		mes "どうかあなたの時間を";
		mes "大事にしてください。";
		next;
		if(select("もう少し留まる","外に出る") == 1) {
			mes "[べルザミン・ボタン]";
			mes "ここの雰囲気が";
			mes "気に入ったようですね。";
			mes "では、いくらでも。";
			close;
		}
		break;
	case 2:
		mes "[べルザミン・ボタン]";
		mes "お別れの時間です。";
		mes "好きな飲み物はありますか？";
		next;
		break;
	}
	mes "[べルザミン・ボタン]";
	mes "コップに入っている飲み物を";
	mes "思い浮かべてみてください。";
	mes "スプーンを使ってゆっくりと";
	mes "飲み物をかき混ぜます。";
	mes "そして色が少しずつ変わっていくのを";
	mes "眺めます。";
	close2;
	warp "c_tower1",235,223;
	end;
}

c_tower4,189,40,3	duplicate(べルザミン・ボタン#ct3)	べルザミン・ボタン#ct4	574

c_tower4,79,49,0	warp	CT4_Line_1		1,1,c_tower4,204,104
c_tower4,204,57,0	warp	CT4_Line_2		1,1,c_tower4,79,43
c_tower4,68,46,0	warp	CT4_Stand1_2	1,1,c_tower4,73,154
c_tower4,75,156,0	warp	CT4_Stand2_3	1,1,c_tower4,132,198
c_tower4,133,202,0	warp	CT4_Stand3_4	1,1,c_tower4,140,149
c_tower4,142,151,0	warp	CT4_Stand4_5	1,1,c_tower4,37,66
c_tower4,37,70,0	warp	CT4_Stand5_6	1,1,c_tower4,65,77
c_tower4,68,79,0	warp	CT4_Stand6_7	1,1,c_tower4,198,64
c_tower4,198,59,0	warp	CT4_Stand7_8	1,1,c_tower4,148,99
c_tower4,151,96,0	warp	CT4_Stand8_1	1,1,c_tower4,68,51
c_tower4,70,19,0	warp	Loop1_2			1,1,c_tower4,156,110
c_tower4,153,107,0	warp	Loop2_3			1,1,c_tower4,177,174
c_tower4,171,179,0	warp	Loop3_4			1,1,c_tower4,56,154
c_tower4,51,156,0	warp	Loop4_1			1,1,c_tower4,77,19
