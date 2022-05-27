data <- read.table(
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/plotting/c_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

png(
    filename =
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/images/plot_rotspeed.png"
)

plot(
    data$Time, data$RotSpeed,
    col = "blue",
    type = "l",
    xlab = "Time in s",
    ylab = "Angular velocity in rad/s",
    main = "Kalman Filter simulation - Rotation speed",
    sub = sprintf("Error in measurement: %1.2f, Q for rotation speed: %1.2f", data[1, "RotError"], data[1, "Q_rot"])
)
lines(data$Time, data$MeasRot, col = "red")

legend("topright",
        inset = 0.01,
        cex = 0.9,
        bty = "n",
        y.intersp = 1.3,
        legend = c("State rotation speed", "Measured rotation speed"),
        col = c("blue", "red"),
        pch = c(1, 1))

dev.off()