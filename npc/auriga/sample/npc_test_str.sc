// ΆρΟΜeXg
prontera,164,188,1	script	ΆρeXg	112,{
	set @str$, "ΆρP";
	mes "ΆρΟF" + @str$ ;
	mes "mFF" + @str$ + " ...OK?";
	next;
	mes "δr`eqOKF" + (@str$=="ΆρP");
	mes "δr`eqNGF" + (@str$=="Άρ");
	mes "δr`neOKF" + (@str$!="00000");
	mes "δr`neNGF" + (@str$!="ΆρP");
	mes "δr`gtOKF" + ("aab">"aaa");
	mes "δr`ltNGF" + ("aab"<"aaa");
	next;
	input @str2$;
	mes "όΝf[^Ν " + @str2$ + " Ε·B";
	close;
}
