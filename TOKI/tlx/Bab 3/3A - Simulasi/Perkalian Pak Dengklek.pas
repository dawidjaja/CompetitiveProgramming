var
	tu,wa:array [0..10] of longint;
	wan,thu:string;
	yi,er,lo,gw,w,t,i,temp,n,error:longint;
begin
	readln(yi,er);
	str(yi,wan);
	str(er,thu);
	w:=length(wan);
	t:=length(thu);
	temp:=0;
	for i:=1 to w do
		begin
			val(wan[i],lo,error);
			tu[i]:=lo;
		end;
	for n:=1 to t do
		begin
			val(thu[n],gw,error);
			wa[n]:=gw;
		end;
	for i:=1 to w do
		begin
			for n:=1 to t do	
			begin
				temp:=temp+(tu[i]*wa[n]);
			end;
		end;
	writeln(temp);
end.