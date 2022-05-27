data <- read.table(
    "~/Documents/STAR/Kalman Filter/kalman/1d_acc_filter/plotting/c_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

png(
    filename =
    "~/Documents/STAR/Kalman Filter/kalman/1d_acc_filter/images/plot_meas_acc.png"
)

plot(
    data$Time, data$Acceleration,
    ylim = range(-1.5:1.5),
    col = "blue",
    type = "l",
    xlab = "Time in s",
    ylab = "Acceleration in m/s^2",
    main = "Kalman Filter simulation - Acceleration",
)
lines(data$Time, data$Measurement, col = "red")

legend("topright",
        inset = 0.01,
        cex = 0.9,
        bty = "n",
        y.intersp = 1.3,
        legend = c("State acceleration y", "Measured acceleration y"),
        col = c("blue", "red"),
        pch = c(1, 1))

dev.off()

