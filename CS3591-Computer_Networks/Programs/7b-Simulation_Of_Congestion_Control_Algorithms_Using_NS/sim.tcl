# Create simulator
set ns [new Simulator]

# Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

# Create links with bandwidth, delay, and queue type
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 0.3Mb 200ms DropTail
$ns duplex-link $n3 $n4 0.5Mb 40ms DropTail
$ns duplex-link $n3 $n5 0.5Mb 30ms DropTail

# Create TCP source and sink agents
set tcp1 [new Agent/TCP/Reno]
$ns attach-agent $n0 $tcp1

set sink1 [new Agent/TCPSink]
$ns attach-agent $n4 $sink1

# Connect source and sink
$ns connect $tcp1 $sink1

# Setup an FTP traffic generator on "tcp1"
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set type_ FTP

# Start and stop the traffic
$ns at 0.1 "$ftp1 start"
$ns at 40.0 "$ftp1 stop"

# Set simulation end time
$ns at 50.0 "finish"

# Procedure to plot the congestion window
proc plotWindow {tcpSource outfile} {
    global ns
    set now [$ns now]
    set cwnd [$tcpSource set cwnd_]
    # Record data in a file called congestion.xg
    puts $outfile "$now $cwnd"
    $ns at [expr $now+0.1] "plotWindow $tcpSource $outfile"
}

set outfile [open "congestion.xg" w]
$ns at 0.0 "plotWindow $tcp1 $outfile"

# Procedure to finish the simulation
proc finish {} {
    exec xgraph congestion.xg -geometry 300x300 &
    exit 0
}

# Run the simulation
$ns run
