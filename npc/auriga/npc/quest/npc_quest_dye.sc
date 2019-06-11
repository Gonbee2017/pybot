//==============================================================================
//Ragnarok Online - dye Event Script
//
//  ■ DYE_EVE -> 0〜3
//==============================================================================

alberta_in,133,55,3	script	ルイツ	84,{
	if(DYE_EVE == 2) {
		mes "[商人ルイツ]";
		mes "おお、君か。";
		mes "どうだ？ゲフェンのあの変な化学者を";
		mes "訪ねてみたか？";
		next;
		if(select("モルゲンシュタインについて話す","いや")==1) {
			mes "[商人ルイツ]";
			mes "なんだ、まだ訪ねてないのか。";
			mes "何か溶液を化合してすごい物を";
			mes "作るらしいじゃないか。";
			mes "行ってみるといいぞ。";
		}
		else {
			mes "[商人ルイツ]";
			mes "ん？……";
			mes "用があるのか無いのか……";
		}
		close;
	}
	mes "[商人ルイツ]";
	mes "何の用かな？";
	next;
	setarray .@talk$,"話をする","溶液等について話す","カルボディールを見せる","ディトリミンを見せる","やめる";
	//アイテムを所持してるかどうかで選択肢を決める、出さないものを空文字で埋める
	if(countitem(971) && countitem(972)) {
		set .@word$,"あの溶液";
		cleararray .@talk$[2],"",2;
	}
	else if(countitem(972)) {
		set .@word$,"そのカルボディール";
		set .@talk$[1],"";
		set .@talk$[3],"";
	}
	else if(countitem(971)) {
		set .@word$,"そのディトリミン";
		cleararray .@talk$[1],"",2;
	}
	else {
		cleararray .@talk$[1],"",3;
	}
	switch (select(.@talk$[0],.@talk$[1],.@talk$[2],.@talk$[3],.@talk$[4])) {
	case 1:
		mes "[商人ルイツ]";
		mes "魔法道具を手に入れるために、";
		mes "ゲフェンという街に居たことがある。";
		mes "そこで、一人の変な化学者の噂を";
		mes "聞いたんだ。";
		mes "興味がわいたので、噂をもとに";
		mes "その科学者を訪ねてみたんだ。";
		next;
		mes "[商人ルイツ]";
		mes "でも、結局何も得られなかった。";
		mes "彼は研究に夢中で私のことなど";
		mes "全く目に入っていなかったからだ。";
		next;
		mes "[商人ルイツ]";
		mes "その時、彼が独り言をつぶやいた";
		mes "のを偶然聞いてしまった……";
		mes "「カルボーディル」「ディトリミン」…";
		next;
		mes "[商人ルイツ]";
		mes "最初はただの寝言かと思ったが、";
		mes "商売をして得た知識から、そのうち";
		mes "それがただの水ではないということが";
		mes "わかった。";
		close;
	default:
		mes "[商人ルイツ]";
		mes "おお！これが" +.@word$+ "か！";
		mes "私も噂には聞いたが実物を見る";
		mes "のは初めてだ。良く手に入れたな〜";
		mes "でも、これを何に使うのか私には";
		mes "さっぱりだ。奴じゃないとな……";
		next;
		mes "[商人ルイツ]";
		mes "冒険者である君は、きっとこの";
		mes "溶液の謎を解きたいだろう。";
		mes "珍しいものを見せてもらったお礼に";
		mes "その化学者の居場所を�ﾍえておこう。";
		next;
		mes "[商人ルイツ]";
		mes "昔のことだから正確な場所までは";
		mes "覚えてないが、ゲフェンに住んでいる";
		mes "ことは間違いないだろう。";
		mes "^0000FFモルゲンシュタイン^000000という";
		mes "名前だったな。";
		next;
		mes "[商人ルイツ]";
		mes "詳しいことはゲフェンで聞いて";
		mes "みてくれ。";
		mes "それでは幸運を祈る。";
		set DYE_EVE,1;
		close;
	case 5:
		mes "[商人ルイツ]";
		mes "ふーむ……";
		close;
	}
}

geffen,184,114,6	script	アウルディフォン	82,{
	if(DYE_EVE == 2) {
		mes "[ゲフェン住民 アウルディフォン]";
		mes "運命がもう一度、";
		mes "私達を導いたんですね。";
		mes "あなたが来ることを待って";
		mes "おりました。";
		mes "で……貴方が探している人には";
		mes "会えましたか？";
		next;
		if(select("モルゲンシュタインについて話す","やめる")==1) {
			mes "[ゲフェン住民 アウルディフォン]";
			mes "まだ会っていないんですね。";
			mes "彼は鍛冶屋の2階に住んでいます。";
			mes "用心して下さい！";
			mes "彼に近づき過ぎるのは避けた方が";
			mes "良いです……";
		}
		else {
			mes "[ゲフェン住民 アウルディフォン]";
			mes "あなたの顔からは、ある意志が";
			mes "感じられました。でも、あなたは";
			mes "私に何も話そうとしないんですね……";
			mes "私は貴方を友達だと思っていたのに……";
			mes "それは私だけの錯覚でしたか？";
		}
		close;
	}
	mes "[ゲフェン住民 アウルディフォン]";
	mes "一度過ぎ去った時間は、どんな偉大な";
	mes "魔法を使っても戻ってこないんです。";
	mes "私がこんな風に話している";
	mes "この瞬間にも時間は流れています。";
	mes "なのに、一体なぜ私を呼んだんですか？";
	next;
	if(DYE_EVE > 0)
		set .@talk$,"モルゲンシュタインについて聞く";
	switch (select("話をする",.@talk$,"やめる")) {	//フラグの0のときは2番目の選択肢出ない
	case 1:
		mes "[ゲフェン住民 アウルディフォン]";
		mes "魔法の力を研究し、追求する私も";
		mes "普通の人とは言えません。でも、";
		mes "この世には本当に稀有な人が";
		mes "多いようですね……";
		next;
		mes "[ゲフェン住民 アウルディフォン]";
		mes "貴方なら、何か一つに全てをかけて";
		mes "取組むことができますか？";
		mes "周辺の全てを諦めたまま……";
		mes "まるで、狂ったみたいに……";
		close;
	case 2:
		set DYE_EVE,2;	//フラグが3のときでも2に戻される（仕様）
		mes "[ゲフェン住民 アウルディフォン]";
		mes "あの気違いについて知っているなら、";
		mes "貴方も一般とは距離がありそうですね。";
		mes "あの人について知りたいという人は";
		mes "多いように見えるのですが……";
		next;
		mes "[ゲフェン住民 アウルディフォン]";
		mes "彼の詳細を説明することは、";
		mes "私には無理です。ごめんなさい……";
		mes "でも、理解してください。";
		mes "私にできうる最大限は、彼の居場所を";
		mes "教えることだけです。";
		next;
		mes "[ゲフェン住民 アウルディフォン]";
		mes "彼は鍛冶屋の2階に住んでいます。";
		mes "用心して下さい！";
		mes "彼に近づき過ぎるのは避けた方が";
		mes "良いです……";
		close;
	case 3:
		mes "[ゲフェン住民 アウルディフォン]";
		mes "あなたの顔からは、ある意志が";
		mes "感じられました。でも、あなたは";
		mes "私に何も話そうとしないんですね……";
		next;
		mes "[ゲフェン住民 アウルディフォン]";
		mes "残念ですが、私にはどうしようも";
		mes "ありません……人間もまた、大自然の";
		mes "一部……即ち、人間の意志は……";
		mes "大自然の流れのようなものですから。";
		close;
	}
}

geffen_in,141,140,3	script	モルゲンシュタイン	121,{
	switch(DYE_EVE) {
	case 0:
	case 1:
		mes "[化学者モルゲンシュタイン]";
		mes "ヒヒヒヒ……くんくん……";
		mes "久しぶりに肉の臭いがするな。";
		mes "人間……人間か。";
		mes "それも生きている人間……";
		mes "ヒヒヒヒヒヒ";
		close;
	case 2:
		set DYE_EVE,3;
		mes "[化学者モルゲンシュタイン]";
		mes "ヒヒヒヒ……ようこそ。";
		mes "ヒヒヒヒ……ヒヒヒヒヒッ……";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "あ……失礼……ヒヒヒヒ……";
		mes "私は……生きている人間をみるのが";
		mes "久しぶりで。なんの用だ？";
		break;
	case 3:
		mes "[化学者モルゲンシュタイン]";
		mes "ヒヒヒヒ……ようこそ。";
		mes "ヒヒヒヒ……ウヒヒヒヒッ……";
		break;
	}
	next;
	switch (select("今やっている研究について聞く","研究品を作ってくれと頼む","やめる")) {
	case 1:
		mes "[化学者モルゲンシュタイン]";
		mes "ヒヒヒヒ……どこかで私の研究について";
		mes "聞いてきたみたいだな……";
		mes "そう……ま、全部知ってるだろうから";
		mes "隠さずに話してやる……いや……";
		mes "隠すこともないだろ……ヒヒヒヒヒ……";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "実は……私の研究はもう完成している…";
		mes "この私の天才的頭脳にできないことは";
		mes "ない……ヒヒヒ……";
		mes "時間が問題であるだけだ……";
		mes "時間……ヒヒヒッ……";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "……その研究について知りたいと";
		mes "言ったな……それはとっても簡単な";
		mes "もんさ……水に溶けない物を";
		mes "溶かす方法を発見しようとしただけさ。";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "興味津々じゃないか？";
		mes "あの堅い岩と鉄の固まりを";
		mes "力のない液体に溶かす方法!!!";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "何もかもがどろどろ〜〜〜";
		mes "どろどろになるだろう!!ヒヒ!!!";
		mes "……ヒヒヒヒッ!!……どろどろ!!!";
		mes "ヒヒヒヒッヒヒ!!!!";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "へ……へ……はぁ……はぁ……";
		mes "と、とにかく……まだ全てを";
		//mes "溶かすことはできないが、。";	//本鯖仕様
		mes "溶かすことはできないが、";
		mes "いくつか発見したことがある。";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "この方法で君が想像できるより、";
		mes "ずっと多くのものが作り出せるだろう";
		mes "……君が願うなら!!";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "……ああ……身体中の循環が活性化し";
		mes "顔が赤くなるこの感じ……考えるだけで";
		mes "頭の中に愉快な液体が分泌され、";
		mes "快楽の嬉しさに満ちるこの感じ……";
		mes "ああああ……";
		close;
	case 2:
		mes "[化学者モルゲンシュタイン]";
		mes "ヒヒヒヒッ……";
		mes "やっぱり君も興味があったんだ。";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "そう……そうだ……世の中誰だって";
		mes "興味を持たざるを得ないだろ……";
		mes "愉快で、興奮すること……フフフフ";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "さあ……何を作り出したいかい??";
		mes "……うん？ヒヒヒヒ";
		next;
		if(select("中和剤","混合剤")==1) {
			set .@need,971;
			set .@price,3000;
			set .@gain,973;
		}
		else {
			set .@need,972;
			set .@price,4000;
			set .@gain,974;
		}
		mes "[化学者モルゲンシュタイン]";
		mes "お……" +getitemname(.@gain)+ "を作りたいと言ったかい";
		mes "……フ フ フ フ……では、";
		mes "その遊戯のために準備する物を";
		mes "教えてやる。";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "……どれ……お……お………";
		mes "ああ……はあ……";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "お……思い出した……そう……";
		mes "アルコール……と……" +getitemname(.@need);
		mes "……そしてそれを保管できる空きビン…";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "この三つの物さえあれば作れる……";
		mes "そして、私に天才的な頭脳と技術に";
		mes "対して感謝を頼みたい……ヒヒヒヒッ";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "そんなに負担のかかるもんじゃない……";
		mes "大したものが欲しいわけではない……";
		mes "……フ フ フ フ";
		mes "よ〜く聴け……" +.@price+ " zenyさえ";
		mes "出せばいい……ヒヒヒヒ";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "お……お……ひょっとして高いと";
		mes "思ってるわけじゃないだろ？";
		mes "……私には感じられる……";
		mes "君には私のような冒険と創造の欲望が";
		mes "あることを！";
		mes "……ヒヒヒヒヒヒヒヒヒヒヒッ";
		next;
		mes "[化学者モルゲンシュタイン]";
		mes "さあ……始めるか？";
		next;
		if(select("作る","やめる")==2) {
			mes "[化学者モルゲンシュタイン]";
			mes "フ……フフフフフ……";
			close;
		}
		if(countitem(970)<1 || countitem(.@need)<1 || countitem(713)<1 || Zeny<.@price) {
			mes "[化学者モルゲンシュタイン]";
			mes "フフフフ……足りない……";
			mes "ハア……ハア……早く……早く……";
			mes "材料を集めて来たまえ!!";
			mes "遊戯はその後に……フフフフフ";
			close;
		}
		mes "[化学者モルゲンシュタイン]";
		mes "おおお……ヒヒヒヒヒヒ……";
		mes "そう……こうして……そう……";
		mes "もっと……ヒヒヒヒヒ";
		mes "……アア……アハ……ハ……アハ……";
		mes "おお……おお！";
		mes "……おおおおおっ!!!!!!!!!";
		next;
		delitem 970,1;
		delitem .@need,1;
		delitem 713,1;
		set Zeny,Zeny-.@price;
		getitem .@gain,1;
		mes "[化学者モルゲンシュタイン]";
		mes "……はあ……";
		close;
	case 3:
		mes "[化学者モルゲンシュタイン]";
		mes "ヒヒ……ヒヒヒヒ……";
		close;
	}
}

prontera,78,150,3	script	ダイレン	90,{
	mes "[村の乙女ダイレン]";
	mes "はぁ……この頃";
	mes "広場に人が多くて複雑だわ。";
	mes "けほんけほん……";
	next;
	mes "[村の乙女ダイレン]";
	mes "あら？なに、この塵〜、不潔だわ〜";
	mes "首都だからと言って、どこでも";
	mes "綺麗ってわけにはいかないのね〜。";
	mes "あらら……それより、何かご用？";
	next;
	if(select("話をする","やめる")==2) {
		mes "[村の乙女ダイレン]";
		mes "あら〜何？人に話しかけておいて。";
		mes "……変な人。";
		close;
	}
	mes "[村の乙女ダイレン]";
	mes "もしかして、パーティとかドレスに";
	mes "興味あるのかしら？ホホホホ";
	mes "この頃の流行の最先端は、";
	mes "なんといっても華麗な色で飾られた";
	mes "ドレスですわ。";
	next;
	mes "[村の乙女ダイレン]";
	mes "その魂さえ奪われそうな色を";
	mes "出すためには、砂漠の都市モロクだけで";
	mes "作られている染料を使用しなきゃ";
	mes "ダメらしいけど……";
	mes "その染料の値段が想像を超えるって。";
	next;
	mes "[村の乙女ダイレン]";
	mes "ああ……一度だけでいいから";
	mes "着てみたいわ……";
	close;
}

morocc_in,146,99,3	script	ザバドリハン	58,{
	mes "[染料製作者ザバドリハン]";
	mes "やぁ……今日は本当に暑いね。";
	mes "こんな天気こそ染料作りにピッタリさ！";
	next;
	switch (select("話をする","染料をつくる","やめる")) {
	case 1:
		mes "[染料製作者ザバドリハン]";
		mes "君に話すことは特にないけど……";
		mes "そうだね、私の過去の話でよかったら";
		mes "聴かせるよ。";
		mes "少し長くてつまんないかも知れないけど";
		mes "聴いてみるかい？";
		next;
		if(select("聴く","聴かない")==2) {
			mes "[染料製作者ザバドリハン]";
			mes "あはは……やれやれ……";
			mes "私みたいな染料職人の話を";
			mes "聞いてくれるはずないか。";
			mes "ハハハハッ……";
			close;
		}
		mes "[染料製作者ザバドリハン]";
		mes "物心がつく前から……";
		mes "私の父は染料を作っていた。";
		mes "数えられないほど長い時間、";
		mes "父はずっと染料を作っていた。";
		next;
		mes "[染料製作者ザバドリハン]";
		mes "そう……母が病気で死んだ時までも";
		mes "……染料作りをやめなかった。";
		mes "その時は、そんな父が憎かった……";
		next;
		mes "[染料製作者ザバドリハン]";
		mes "そんな父が嫌で染料作りも嫌いになって";
		mes "若い頃は家を出て、何でもやって";
		mes "みたりしたけれど……";
		next;
		mes "[染料製作者ザバドリハン]";
		mes "でも……私は今、再び家に戻って";
		mes "染料作りの家業を継いでいる。";
		mes "血は誤魔化せなかったみたいさ……";
		mes "この仕事を始めて、もう……";
		mes "15年経ったな。";
		next;
		mes "[染料製作者ザバドリハン]";
		mes "この頃になって感じてるのは……";
		mes "今は父が理解できるってことさ。";
		mes "父がどうして全てを捨てたまま、";
		mes "染料作りに夢中になったかを……";
		next;
		mes "[染料製作者ザバドリハン]";
		mes "それは多分、何回も繰り返した作業で";
		mes "重なって染まっていく、あの色……";
		mes "何十回何千回、夢の中で見たような";
		mes "あの幻の色を出すためだったんだろう…";
		next;
		mes "[染料製作者ザバドリハン]";
		mes "フッ……";
		mes "どうしてそれが分かるのかって？";
		mes "それは……今の私がそうだからさ。";
		mes "何年前からだったか……";
		mes "色の言うことが分かるようになった";
		mes "あの瞬間から……";
		next;
		mes "[染料製作者ザバドリハン]";
		mes "見てろ！";
		mes "私は父が成し遂げられなかった";
		mes "あの色を必ず実現させて見せるさ！";
		close;
	case 2:
		mes "[染料製作者ザバドリハン]";
		mes "よし！君さえよかったら、作ろう。";
		mes "私が必ず君の欲しい色を";
		mes "出してやると、約束しよう。";
		next;
		mes "[染料製作者ザバドリハン]";
		mes "で、どんな色の染料が作りたいかい？";
		mes "作ろうとする色によって手数料が";
		mes "違うよ。";
		next;
		mes "[染料製作者ザバドリハン]";
		mes "なぜかって？";
		mes "この世には簡単に作れる色と、";
		mes "そうじゃない色があるんだ。";
		mes "手数料が高いなんて思わないでおくれ。";
		mes "この染料は私の魂が込められている、";
		mes "特別な物なんだからね！";
		next;
		switch (select("赤色の染料","黄色の染料","��色の染料","録色の染料","紅色の染料","紫色の染料","白色の染料","�K色の染料","やめる")) {
			case 1:
				mes "[染料製作者ザバドリハン]";
				mes "うーむ……赤色の染料を作るためには";
				mes "赤ハーブ 30個 と 中和剤、";
				mes "そして空きビン 1個が必要だ。";
				mes "手数料は 3000 zenyになる。";
				setarray .@need,507,973,713;
				setarray .@amount,30,1,1;
				set .@price,3000;
				set .@gain,975;
				break;
			case 2:
				mes "[染料製作者ザバドリハン]";
				mes "うーむ……黄色の染料を作るためには";
				mes "黄ハーブ 30個 と 中和剤、";
				mes "そして空きビン 1個が必要だ。";
				mes "手数料は 3000 zenyになる。";
				setarray .@need,508,973,713;
				setarray .@amount,30,1,1;
				set .@price,3000;
				set .@gain,976;
				break;
			case 3:
				mes "[染料製作者ザバドリハン]";
				mes "うーむ……青色の染料を作るためには";
				mes "青ハーブ 20個 と 中和剤、";
				mes "そして空きビン 1個が必要だ。";
				mes "手数料は 3500 zenyになる。";
				setarray .@need,510,973,713;
				setarray .@amount,20,1,1;
				set .@price,3500;
				set .@gain,978;
				break;
			case 4:
				mes "[染料製作者ザバドリハン]";
				mes "うーむ……緑色の染料を作るためには";
				mes "青ハーブ 5個 と 緑ハーブ 20個";
				mes "黄ハーブ 20個　中和剤 と 混合剤、";
				mes "そして空きビン 1個が必要だ。";
				mes "材料が多いから、間違いないように。";
				mes "手数料は 5000 zenyになる。";
				setarray .@need,510,973,713,511,508,974;
				setarray .@amount,5,1,1,20,20,1;
				set .@price,5000;
				set .@gain,979;
				break;
			case 5:
				mes "[染料製作者ザバドリハン]";
				mes "うーむ……紅色の染料を作るためには";
				mes "赤ハーブ 20個 と 黄ハーブ 20個";
				mes "中和剤 と 混合剤、";
				mes "そして空きビン 1個が必要だ。";
				mes "手数料は 5000 zenyになる。";
				setarray .@need,507,973,713,974,508;
				setarray .@amount,20,1,1,1,20;
				set .@price,5000;
				set .@gain,980;
				break;
			case 6:
				mes "[染料製作者ザバドリハン]";
				mes "うーむ……紫色の染料を作るためには";
				mes "青ハーブ 10個と赤ハーブ 30個";
				mes "中和剤 と 混合剤、";
				mes "そして空きビン 1個が必要だ。";
				mes "手数料は 5000 zenyになる。";
				setarray .@need,507,973,713,974,510;
				setarray .@amount,20,1,1,1,10;
				set .@price,5000;
				set .@gain,981;
				break;
			case 7:
				mes "[染料製作者ザバドリハン]";
				mes "うーむ……白色の染料を作るためには";
				mes "白ハーブ 30個 と 中和剤";
				mes "そして空きビン 1個が必要だ。";
				mes "手数料は 3000 zenyになる。";
				setarray .@need,509,973,713;
				setarray .@amount,30,1,1;
				set .@price,3000;
				set .@gain,982;
				break;
			case 8:
				mes "[染料製作者ザバドリハン]";
				mes "うーむ……黒色の染料を作るためには";
				mes "赤、黄、緑のハーブが 30個ずつ";
				mes "青ハーブ 5個 と 中和剤、混合剤";
				mes "そして空きビン 1個が必要だ。";
				mes "作成が難しく、長い時間が必要だから";
				mes "手数料は 7000 zenyになる。";
				setarray .@need,507,973,713,510,508,974,511;
				setarray .@amount,30,1,1,5,30,1,30;
				set .@price,7000;
				set .@gain,983;
				break;
			case 9:
				mes "[染料製作者ザバドリハン]";
				mes "何？今さら気が変わった？";
				mes "そんな……";
				close;
		}
		next;
		mes "[染料製作者ザバドリハン]";
		mes "さあ！準備できていると思うが……";
		mes "作業を始めるかい？";
		next;
		if(select("染料をつくる","やめる")==2) {
			mes "[染料製作者ザバドリハン]";
			mes "何？今さら気が変わった？";
			mes "そんな……";
			close;
		}
		//各アイテムに対して所持数のチェックとZeny判定
		for(set .@i,0; .@i<getarraysize(.@need); set .@i,.@i+1) {
			if(countitem(.@need[.@i]) < .@amount[.@i] || Zeny<.@price) {
				mes "[染料製作者ザバドリハン]";
				mes "ふーむ、足りないね……";
				mes "その材料では、満足な色が出せないな。";
				mes "もっと材料を集めて来てくれ。";
				close;
			}
		}
		for(set .@i,0; .@i<getarraysize(.@need); set .@i,.@i+1) {
			delitem .@need[.@i],.@amount[.@i];
		}
		set Zeny,Zeny-.@price;
		getitem .@gain,1;
		mes "[染料製作者ザバドリハン]";
		mes "ふーむ……ま、これなら良く";
		mes "できたほうさ。";
		mes "とっても濃い色に仕上がったよ。";
		mes "もちろん、私はこれ以上に魅惑的な色を";
		mes "作り出すために努力するさ……";
		next;
		mes "[染料製作者ザバドリハン]";
		mes "では、染料がまた必要になったら";
		mes "いつでも来なさい。";
		close;
	case 3:
		mes "[染料製作者ザバドリハン]";
		mes "自慢じゃないが、私は染色薬を作る";
		mes "技術をもっているのさ。";
		mes "もし染料が必要なら、私に";
		mes "頼んでくれればいいさ。";
		mes "悪くない値段で作ってあげるよ。";
		close;
	}
}

prt_in,284,168,3	script	ジネダインレフル	55,{
	mes "[衣類加工士ジネダイン=レフル]";
	mes "十一……十二……うーむ、よし。";
	mes "今夜のパーティまでは、。";
	mes "どうにか間に合いそうだ。";
	next;
	mes "[衣類加工士ジネダイン=レフル]";
	mes "あ！";
	mes "お客様、いらっしゃいませ。";
	mes "何の用でいらしたのですか？";
	next;
	switch (select("話をする","服を染める","やめる")) {
	case 1:
		mes "[衣類加工士ジネダイン=レフル]";
		mes "ドレス注文が殺到しているところを";
		mes "見ると、余裕のあるお嬢さんにとって";
		mes "とても良い世になったようですね。";
		next;
		mes "[衣類加工士ジネダイン=レフル]";
		mes "贅沢と思ってるわけではありませんが…";
		mes "まぁ、いいでしょう。";
		mes "世にはそんな人達がいるから、";
		mes "人間の追及する美しさが発展できると";
		mes "言うものです。";
		next;
		mes "[衣類加工士ジネダイン=レフル]";
		mes "毛も鱗もない人間が、自分の個性と";
		mes "美しさを表現できる数少ない方法は";
		mes "服で着飾るしかないのですから……";
		mes "あ、これは私だけの考えですがね。";
		next;
		mes "[衣類加工士ジネダイン=レフル]";
		mes "ハハハ……そういう視点で見たとき";
		mes "私なりに考えてみたこの仕事は、";
		mes "とても崇高な仕事ではないかと";
		mes "思います。やりがいもありますし。";
		next;
		mes "[衣類加工士ジネダイン=レフル]";
		mes "あなたにも感じられますか？";
		mes "アンバランスで平凡な、あの布と革を";
		mes "綺麗な色で染めたとき……";
		mes "まるで新しい命が生れるように";
		mes "ほとばしるその情熱とエネルギー……";
		next;
		mes "[衣類加工士ジネダイン=レフル]";
		mes "とてもキツクて難しい作業だけれど、";
		mes "完成されたドレスを見た時に感じられる";
		mes "あの喜悦だけで、充分、";
		mes "苦労が報われます。";
		close;
	case 2:
//		mes "[衣類加工士ジネダイン=レフル]";
//		mes "ほお……あなたも服を染色しに来たと";
//		mes "いうことですね？";
//		mes "いいでしょう。";
//		mes "今度の仕事は面白そうですね。";
//		next;
//		mes "[衣類加工士ジネダイン=レフル]";
//		mes "でも染色に必要な材料は";
//		mes "残念ながら私から提供しておりません。";
//		mes "全部持って来ていただかないと……";
//		mes "私が必要とする材料が全部";
//		mes "揃っているか見てみましょうか？";
//		next;
		mes "[衣類加工士ジネダイン=レフル]";
		mes "あ……あなたも服を染色しに";
		mes "いらしたんですね？";
		next;
		mes "[衣類加工士ジネダイン=レフル]";
		mes "申し訳ございませんが、今はあなたの";
		mes "服を染色してさしあげる時間が";
		mes "ありません。滞っている注文を";
		mes "仕上げるだけで精一杯ですので……";
		next;
		mes "[衣類加工士ジネダイン=レフル]";
		mes "申し訳ございませんが、";
		mes "今度また寄ってくださいませんか？";
		close;
	case 3:
		mes "ごゆっくりして行ってください。";
		mes "私は忙しくて手を離せないので、";
		mes "お相手することは出来ませんが。";
		close;
	}
}

//■キャラ永続変数hairColorを廃止
prt_in,243,168,4	script	ヨボビチ	91,{
	if(Sex==0) {
		if(rand(2)) {
			mes "[美容師ヨボビチ]";
			mes "いらっしゃいませ〜。";
			mes "あら！お姉さん…";
			mes "髪がだいぶ傷んでいますね〜。";
			mes "私に任せてください。";
		}
		else {
			mes "[美容師ヨボビチ]";
			mes "あら！お姉さん、";
			mes "髪染めしてみては";
			mes "いかがでしょう？";
			mes "もっと綺麗になれますよ！";
			mes "思い切ってイメージチェンジ";
			mes "してみませんか？";
		}
	}
	if(Sex==1) {
		mes "[美容師ヨボビチ]";
		mes "いらっしゃいませ。";
		mes "あらら…こんなに髪が傷んで…";
		mes "ちゃんとしたお手入れが必要ですね。";
		mes "それではお座りください。";
	}
	next;
	switch (select("髪を染める","髪染めについて","やめる")) {
	case 1:
		mes "[美容師ヨボビチ]";
		mes "まあ、勇気を出しましたね〜。";
		mes "さあ！それでは思い切って";
		mes "変身してみましょう！";
		mes "どのお色がよろしいですか？";
		//色文字、色番号、アイテムIDの配列をセット
		setarray .@word$,"赤","黄","紫","紅","緑","青","白","黒";
		setarray .@color,8,1,2,3,4,5,6,7;
		setarray .@itemid,975,976,981,980,979,978,982,983;
		while(1) {
			next;
			set .@j,select("赤色でお願いします","黄色でお願いします","紫色でお願いします","紅色でお願いします",
					"緑色でお願いします","青色でお願いします","白色でお願いします","黒色でお願いします","やっぱり今のままで")-1;
			mes "[美容師ヨボビチ]";
			mes "それでは" +.@word$[.@j]+ "色に染めますね。";
			next;
			if(select("はい！","やっぱやめる！")==2) {
				if(.@dyecount) {	//1回以上すでに染めたとき
					mes "[美容師ヨボビチ]";
					mes "今の色が気に入られたんですね。";
					mes "お似合いですよ〜。";
				}
				else {
					mes "[美容師ヨボビチ]";
					mes "そのままでいらっしゃるのですね。";
					mes "少しもったいない気もしますが、";
					mes "今の色もお似合いですよ。";
				}
				close;
			}
			if(Zeny<5000) {
				mes "[美容師ヨボビチ]";
				mes "あ、お金が足りないようです。";
				close;
			}
			if(countitem(.@itemid[.@j])<1) {
				mes "[美容師ヨボビチ]";
				mes "あの、" +.@word$[.@j]+ "色に染めるには";
				mes "「" +.@word$[.@j]+ "色の染料」が必要です。";
				close;
			}
			if(getlook(6) == .@color[.@j]) {
				mes "[美容師ヨボビチ]";
				mes "あ、その色はお客様の";
				mes "今の髪と同じです。";
				continue;
			}
			set .@dyecount,1;
			set Zeny,Zeny-5000;
			delitem .@itemid[.@j],1;
			setlook 6,.@color[.@j];
			mes "[美容師ヨボビチ]";
			mes "どうでしょう、他の色に";
			mes "染めてみますか？";
			next;
			if(select("はい","いいえ")==2) {
				mes "[美容師ヨボビチ]";
				mes "は〜い、";
				mes "お似合いです！";
				mes "またのお越しをお待ちして";
				mes "おります〜。";
				close;
			}
			mes "[美容師ヨボビチ]";
			mes "はい、かしこまりました。";
			mes "ご希望の色をどうぞ。";
		}
	case 2:
		mes "[美容師ヨボビチ]";
		mes "気持ちが浮かない時、";
		mes "恋人にふられた時、";
		mes "素敵に見せたい人がいる時、";
		mes "おしゃれしてみたい時、";
		mes "そんな時、イメージチェンジをして";
		mes "気分も一新してみませんか？";
		next;
		mes "[美容師ヨボビチ]";
		mes "もし、こちらに髪を染める染料を";
		mes "お持ちになったら、素敵な髪を";
		mes "もっと素敵に変えてさしあげます。";
		mes "料金なんか気にしちゃいけません。";
		mes "もっと良い物が得られるのですから。";
		next;
		mes "[美容師ヨボビチ]";
		mes "* 材料及び料金案内 *";
		mes "・^FF3080ご希望の色の染料 1個^000000";
		mes "・^FF3080髪染め料金 5000ｚ^000000";
		close;
	case 3:
		mes "[美容師ヨボビチ]";
		mes "男でも女でも…人は美しくなる";
		mes "権利と義務があります。";
		close;
	}
}
