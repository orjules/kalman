data <- read.table(
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/plotting/c_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

png(
    filename =
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/images/plot_pos.png"
)

plot(
    data$PosX, data$PosY,
    col = "blue",
    type = "l",
    xlab = "Position X in m",
    ylab = "Position Y in m",
    main = "Kalman Filter simulation - Acceleration",
    sub = sprintf("Error in measurement: %1.2f, Q for acceleration: %1.2f", data[1, "AccError"], data[1, "Q_acc"])
)

legend("topright",
        inset = 0.01,
        cex = 0.9,
        bty = "n",
        y.intersp = 1.3,
        legend = c("State position x and y"),
        col = c("blue"),
        pch = c(1))

dev.off()