data <- read.table(
    "./1d_acc_filter/plotting/c_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

png(
    filename =
    "./1d_acc_filter/images/plot_vel.png"
)

plot(
    data$Time, data$Velocity,
    ylim = range(-1.5:1.5),
    col = "blue",
    type = "l",
    xlab = "Time in s",
    ylab = "Velocity in m/s",
    main = "Kalman Filter simulation - Velocity",
    sub = sprintf("Error in measurement: %1.2f, Q for acceleration: %1.2f", data[1, "Meas_Err"], data[1, "Q_acc"])
)
lines(data$Time, data$Measurement, col = "red")
abline(h=0)

legend("topright",
        inset = 0.01,
        cex = 0.9,
        bty = "n",
        y.intersp = 1.3,
        legend = c("State velocity", "Measured acceleration"),
        col = c("blue", "red"),
        pch = c(1, 1))

dev.off()

