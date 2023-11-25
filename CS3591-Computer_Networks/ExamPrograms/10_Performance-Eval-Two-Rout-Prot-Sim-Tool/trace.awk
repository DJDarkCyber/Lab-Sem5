BEGIN {
    c = 0;
}

{
    if ($1 == "d") {
        c++;
        # Optionally, you can print other fields from the trace.
        # printf("%s\t%s\n", $5, $11);
    }
}

END {
    printf("The number of packets dropped = %d\n", c);
}
