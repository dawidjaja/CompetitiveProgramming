var
    temp,a,b: integer;
procedure Swap(var a, b: integer);
begin
    temp := a;
    a := b;
    b := temp;
end;
begin
    readln(a, b);
    Swap(a, b);
    writeln(a, ' ', b);
end.