var
	a,b,msk,zxc,d,e,f,mid,x,y,z,bsa,bsb,i,cek,temp,tes:longint;
begin
	readln(msk);
	for zxc:=1 to msk do
		begin
		readln(a,b);
		if a<b then
			begin
			temp:=a;
			a:=b;
			b:=temp;
			tes:=1
			end;
		d:=a div 100;
		e:=(a-d*100) div 10;
		f:=(a-d*100-e*10);
		x:=b div 100;
		y:=(b-x*100) div 10;
		z:=(b-x*100-y*10);
		cek:=0;
		for i:=10 to 15000 do
			begin
			bsa:=((d*i*i)+(e*i)+f);
			a:=i;
			b:=15000;
			while a<>b do
				begin
				mid:=(a+b) div 2;
				bsb:=(x*mid*mid+y*mid+z);
				if bsa=bsb then
					begin
					if tes=1 then
						begin
						writeln(mid,' ',i);
						end
					else
						begin
						writeln(i,' ',mid);
						end;
					cek:=1;
					break;
					end;
				if bsa>bsb then
					begin
					if a=mid then
						begin
						break;
						end;
					a:=mid;
					end;
				if bsa<bsb then
					begin
					b:=mid;
					end;
				if b<a then
					begin
					break;
					end;
				end;
			if cek=1 then
				begin
				break;
				end;
			end;
		end;
end.