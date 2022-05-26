data <- read.table(
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/plotting/debug_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

png(
    filename =
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/images/plot_meas_acc.png"
)

plot(
    data$Time, data$AccY,
    ylim = range(-2:2),
    col = "blue",
    type = "p",
    xlab = "Time in s",
    ylab = "Acceleration in m/s^2",
    main = "Kalman Filter simulation - Acceleration",
)
points(data$Time, data$MeasAccY, col = "red")

legend("topright",
        inset = 0.01,
        cex = 0.9,
        bty = "n",
        y.intersp = 1.3,
        legend = c("State acceleration y", "Measured acceleration y"),
        col = c("blue", "red"),
        pch = c(1, 1))

dev.off()
