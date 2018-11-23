./a.out 1 $1 > out_ft_printf
./a.out 2 $1 > out_printf
diff out_ft_printf out_printf
